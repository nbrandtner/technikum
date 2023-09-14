<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Hotel Webseite</title>
    <!-- Füge hier deine CSS- und JavaScript-Dateien hinzu -->
</head>
<body>
    <header>
        <h1>Hotel Webseite</h1>
        <!-- Hier kannst du die Navigationsleiste für verschiedene Benutzerrollen erstellen -->
        <nav>
            <?php
            // Überprüfe die Benutzerrolle und zeige entsprechende Links an
            if (/* Benutzer ist eingeloggt und Administrator */) {
                echo '<a href="admin/news.php">News verwalten</a>';
            } elseif (/* Benutzer ist eingeloggt */) {
                echo '<a href="profile.php">Profil</a>';
                echo '<a href="reservations.php">Reservierungen</a>';
            } else {
                echo '<a href="register.php">Registrieren</a>';
                echo '<a href="login.php">Anmelden</a>';
            }
            ?>
        </nav>
    </header>

    <main>
        <!-- Hier kannst du den Hauptinhalt der Seite einfügen -->
    </main>

    <footer>
        <p>&copy; <?php echo date("Y"); ?> Hotel Webseite</p>
    </footer>
</body>
</html>