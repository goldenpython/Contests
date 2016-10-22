/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 1971. Graphics Settings                                          */
/*   http://acm.timus.ru/problem.aspx?num=1971                                */


#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>

typedef double REAL;

class COption {
	public:
		COption(REAL lfValue, bool bIsOn = true) : m_lfValue(lfValue), m_bIsOn(bIsOn) {};

		bool GetIsOn() const { return m_bIsOn; }
		void SetIsOn(bool bIsOn) { m_bIsOn = bIsOn; }

		REAL GetValue() const { return m_lfValue; }
		void SetValue(REAL lfValue) { m_lfValue = lfValue; };

	private:
		REAL m_lfValue;
		bool m_bIsOn;
};

void PrintPerformance(REAL lfFps) {
	static const REAL LOG_10 = std::log(10.0);
	static const REAL LOG_60 = std::log(60.0);

	if (lfFps < LOG_10)
		std::cout << "Slideshow" << std::endl;
	else if (lfFps < LOG_60)
		std::cout << "So-so" << std::endl;
	else
		std::cout << "Perfect" << std::endl;
}

int main() {
	std::ios::sync_with_stdio(false);

	int nNoOptions;
	std::cin >> nNoOptions;
	std::unordered_map<std::string, COption> oMapOptions;
	REAL lfTemp = 0;
	for (int nLoop = 0; nLoop < nNoOptions; nLoop++) {
		std::string oOptionName;
		REAL lfValue;

		std::cin >> oOptionName >> lfValue;
		lfValue = std::log(lfValue);

		oMapOptions.emplace(oOptionName, lfValue);
		lfTemp += lfValue;
	}

	int nW, nH, nRate;
	std::cin >> nW >> nH >> nRate;
	
	REAL lfLogRes = std::log(nW * nH);
	REAL lfFps = std::log(nRate) - lfTemp - lfLogRes;
	PrintPerformance(lfFps);

	int nNoChanges;
	std::cin >> nNoChanges;
	for (int nLoop = 0; nLoop < nNoChanges; nLoop++) {
		std::string oOptionName;
		std::cin >> oOptionName;
		if (oOptionName == "Resolution") {
			//long long llTemp = static_cast<long long>(nW * nH);
			lfFps += lfLogRes;
			std::cin >> nW >> nH;
			//nFps = static_cast<int>(nFps * llTemp / (nW * nH));
			lfFps -= (lfLogRes = std::log(nW * nH));
		} else {
			bool bTurnOn = oOptionName == "On";

			std::cin >> oOptionName;
			auto oIt = oMapOptions.find(oOptionName);

			if (oIt->second.GetIsOn()) {
				if (!bTurnOn)
					lfFps += oIt->second.GetValue();
			} else {
				if (bTurnOn)
					lfFps -= oIt->second.GetValue();
			}

			oIt->second.SetIsOn(bTurnOn);
		}

		PrintPerformance(lfFps);
	}

	return 0;
}