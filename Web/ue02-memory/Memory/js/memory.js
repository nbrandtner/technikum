var clock = 0;
var reference = setInterval(startTimer, 1000);

function loadpage() {
	const array = new Array(1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8);
	for (let x = 0; x < array.length; x++) {
		const j = Math.floor(Math.random() * (x + 1));
		const temp = array[x];
		array[x] = array[j];
		array[j] = temp;
	}
	let username = prompt("Please enter your name: ");

	if (username != null) {
		document.getElementById("spielername").innerHTML = username;
	} else {
		document.getElementById("spielername").innerHTML = "Player1";
	}

	for (var i = 0; i < 16; i++) {
		var karte = document.createElement("div");
		karte.className = "karte";
		karte.setAttribute("imgname", "pics/card" + array[i] + ".png");
		karte.setAttribute("onclick", "turncard(this)");
		karte.setAttribute("turned", 0);
		document.getElementById("spielbereich").appendChild(karte);
		if ((i + 1) % 4 == 0) {
			document.getElementById("spielbereich").appendChild(document.createElement("br"));
		}
	}
}

function startTimer() {
	clock++;
	document.getElementById("time").innerHTML = clock;
}

function stoppTimer() {
	clearInterval(reference);
}

var tries = 0;
var turnedCards = 0;
var card1;
var card2;
var foundPairs = 0;
function turncard(cardelement) {
	if (cardelement.getAttribute("turned") == 0 && turnedCards < 2) {
		turnedCards++;
		cardelement.setAttribute("turned", 1);
		cardelement.style.backgroundImage = "url(" + cardelement.getAttribute("imgname") + ")";
		if (turnedCards == 2) {
			card2 = cardelement;
			if (card1.getAttribute("imgname") != cardelement.getAttribute("imgname")) {
				setTimeout(hidecards, 1000);
			} else {
				sucess();
			}
			tries++;
			document.getElementById("versuche").innerHTML = tries;
		} else if (turnedCards == 1) {
			card1 = cardelement;
		}
	}
}
parseInt(flippedCards[0])
function sucess() {
	turnedCards = 0;
	foundPairs++;
	card1.removeAttribute("onclick");
	card2.removeAttribute("onclick");
	card2.style.backgroundImage = "url('pics/memoryBgI.png')";
	card1.style.backgroundImage = "url('pics/memoryBgI.png')";
	if (foundPairs == 8) {
		stoppTimer();
	}
}

function hidecards() {
	card2.style.backgroundImage = "url('pics/memoryBg.png')";
	card1.style.backgroundImage = "url('pics/memoryBg.png')";

	card2.setAttribute("turned", 0);
	card1.setAttribute("turned", 0);
	turnedCards = 0;
}
