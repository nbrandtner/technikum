function calc(operation) {
	var zahl1 = document.getElementById("zahl1").value;
	var zahl2 = document.getElementById("zahl2").value;
	var ergebnis = 0;
	// delete whitespaces and leading zeros
	// https://stackoverflow.com/questions/6676488/remove-leading-zeros-from-a-number-in-javascript (solution to remove leading zeros)
	zahl1 = zahl1.trim();
	zahl1 = zahl1.replace(/^0+/, "");
	zahl2 = zahl2.trim();
	zahl2 = zahl2.replace(/^0+/, "");

	// idk if i couldve used the operation directly (zahl1 + operation + zahl2) or smth like that so i used a switch-case instead
	switch (operation) {
		case "+":
			ergebnis = parseFloat(zahl1) + parseFloat(zahl2);
			break;
		case "-":
			ergebnis = parseFloat(zahl1) - parseFloat(zahl2);
			break;
		case "*":
			ergebnis = parseFloat(zahl1) * parseFloat(zahl2);
			break;
		case "/":
			if (zahl2 == 0) {
				ergebnis = "Error";
				break;
			}
			ergebnis = parseFloat(zahl1) / parseFloat(zahl2);
			break;
	}
	document.getElementById("ergebnis").value = ergebnis;
	var history = document.getElementById("history").value;
	if (ergebnis == "Error") {
		ergebnis = "To Infinity and beyond! (durch 0 teilen ist nicht erlaubt)";
	}

	document.getElementById("history").value = history + zahl1 + " " + operation + " " + zahl2 + " = " + ergebnis + "\n";
}
