<?php
session_start(); // Sitzung starten, um den Benutzerstatus zu speichern

// Überprüfen Sie, ob der Benutzer angemeldet ist und welche Rolle er hat
$role = "anonymous"; // Standardrolle

if (isset($_SESSION['user_role'])) {
    $role = $_SESSION['user_role'];
}

?>

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
            <a href="index.php">Startseite</a>
            <a href="help.php">Hilfe/FAQs</a>
            <a href="impressum.php">Impressum</a>
            <a href="news.php">News-Beiträge</a>
            <?php
            if ($role === "anonymous") {
                echo '<a href="register.php">Registrieren</a>';
            } elseif ($role === "user") {
                echo '<a href="reservation.php">Zimmerreservierung</a>';
                echo '<a href="profile.php">Profil</a>';
            } elseif ($role === "admin") {
                echo '<a href="admin/news_management.php">News verwalten</a>';
                echo '<a href="admin/reservation_management.php">Reservierungen verwalten</a>';
                echo '<a href="admin/user_management.php">Userverwaltung</a>';
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