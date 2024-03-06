const spielbereich = document.getElementById("spielbereich");
const spieler = document.getElementById("spieler");
const versuche = document.getElementById("versuche");
const zeit = document.getElementById("zeit");

let karten = [];
let ausgewahlteKarten = [];
let versucheZaehler = 0;
let zeitZaehler;

function erstelleSpielbereich() {
	spielbereich.style.display = "grid";
	spielbereich.style.gridTemplateColumns = "repeat(4, 1fr)";
	spielbereich.style.gridGap = "5px";
	for (let i = 0; i < 16; i++) {
		const karte = document.createElement("img");
		karte.classList.add("karte", "verdeckt");
		karte.style.draggable = false;
		karte.src = `pics/memoryBg.png`;
		karte.alt = `Karte ${i + 1}`;
		karte.id = i + 1;
		karte.onclick = kartenKlick;
		spielbereich.appendChild(karte);
		karten.push(karte);
		karten.push(karte);
	}
	shuffleArray(karten);
}

function kartenKlick(event) {
	const karte = event.target;
	if (karte.classList.contains("verdeckt")) {
		karte.classList.remove("verdeckt");
		ausgewahlteKarten.push(karte);
		if (ausgewahlteKarten.length === 2) {
			versucheZaehler++;
			versuche.textContent = versucheZaehler;
			if (ausgewahlteKarten[0].alt === ausgewahlteKarten[1].alt) {
				ausgewahlteKarten = [];
			} else {
				setTimeout(() => {
					ausgewahlteKarten[0].classList.add("verdeckt");
					ausgewahlteKarten[1].classList.add("verdeckt");
					ausgewahlteKarten = [];
				}, 1000);
			}
		}
	}
}

function shuffleArray(array) {
	for (let i = array.length - 1; i > 0; i--) {
		const j = Math.floor(Math.random() * (i + 1));
		[array[i], array[j]] = [array[j], array[i]];
	}
}

function startZeit() {
	zeitZaehler = setInterval(() => {
		zeit.textContent = parseInt(zeit.textContent) + 1;
	}, 1000);
}

function endeSpiel() {
	clearInterval(zeitZaehler);
	alert("Das Spiel ist beendet!");
}

erstelleSpielbereich();
startZeit();
