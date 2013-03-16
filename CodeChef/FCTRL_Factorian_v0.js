/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem FACTORIAL / FCTRL                                                */


var stdin = process.stdin;
stdin.resume();
stdin.setEncoding('utf8');

data = "";

stdin.on('data', function (chunk) {
	data += chunk;
});

process.stdin.on('end', function() {
	var lines = data.split(/\W+/);
	
	var NoTests = parseInt(lines[0]);
	for (var i = 1; i <= NoTests; i++) {
		var Number = parseInt(lines[i]);
		
		var pow5 = 0;
		for (var j = 5; j <= Number; j = j * 5) {
			pow5 += Math.floor(Number / j);
		}
		
		process.stdout.write(pow5 + '\n');
	}
	
});