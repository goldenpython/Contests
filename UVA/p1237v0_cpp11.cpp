/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 1237 - Expert Enough?                                            */


#include <iostream>
#include <string>
#include <memory>
#include <list>
#include <algorithm>

using namespace std;

int main() {
	int nNoTestCasesLeft;
	cin >> nNoTestCasesLeft;
	while (nNoTestCasesLeft--) {
		typedef struct MANUFACTURERPRICEINFO{
			MANUFACTURERPRICEINFO(string &&roManufacturer, int nLowPrice, int nHighPrice) : m_oManufacturer(roManufacturer), m_nLowPrice(nLowPrice), m_nHighPrice(nHighPrice) {}
			string m_oManufacturer;
			int m_nLowPrice, m_nHighPrice;
		} ManufacturerPriceInfo;

		int nDatabaseSize;
		cin >> nDatabaseSize;

		list<ManufacturerPriceInfo> oList;
		while (nDatabaseSize--) {
			string oManufacturer;
			int nLowPrice, nHighPrice;

			cin >> oManufacturer >> nLowPrice >> nHighPrice;
			oList.push_back(ManufacturerPriceInfo(move(oManufacturer), nLowPrice, nHighPrice));
		}

		int nQueries;
		cin >> nQueries;
		while (nQueries--) {
			int nPrice, nCount = 0;
			cin >> nPrice;

			auto oPredicate = [&nPrice] (const ManufacturerPriceInfo &roItem) { return nPrice >= roItem.m_nLowPrice && nPrice <= roItem.m_nHighPrice; };
			auto oIt1 = find_if(oList.cbegin(), oList.cend(), oPredicate);
			if (oIt1 != oList.cend()) {
				nCount++;
				auto oIt2 = find_if(std::next(oIt1), oList.cend(), oPredicate);
				if (oIt2 != oList.cend())
					nCount++;
			}

			cout << (nCount == 1 ? oIt1->m_oManufacturer : "UNDETERMINED") << endl;
		}

		if (nNoTestCasesLeft)
			cout << endl;
	}

	return 0;
}