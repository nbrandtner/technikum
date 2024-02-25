function calc(operation) {
	var zahl1 = document.getElementById("zahl1").value;
	var zahl2 = document.getElementById("zahl2").value;
	var ergebnis = 0;
	// idk ob ich das übergebene rechenzeichen auch direkt verwenden könnte also hab ichs mit switch-case gemacht
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
