<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Serenity Haven - Impressum</title>
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-4bw+/aepP/YC94hEpVNVgiZdgIC5+VKNBQNGCHeKRQN+PtmoHDEXuppvnDJzQIu9" crossorigin="anonymous">
        <!-- Füge hier deine CSS-Dateien hinzu, um das Styling anzupassen -->
        <link rel="stylesheet" href="style.css">
    </head>
    <body>
        <?php 
            include 'modal/login.php'; 
            include 'modal/profil.php';
            include 'modal/register.php';
        ?>
        <?php
            include 'header.php';
        ?>
        <div class="icon-container">
        <!--Buttons für verschieden Links/Socials-->
        <div class="icon icon-fill">
            <i class="fa fa-home"></i>
        </div>
        <div class="icon icon-enter">
            <i class="fa fa-user"></i>
        </div>
        <div class="icon icon-expand">
            <i class="fa fa-bars"></i>
        </div>
        <div class="icon icon-collapse">
            <i class="fa fa-sign-in"></i>
        </div>
        <div class="icon icon-rotate">
            <i class="fa fa-phone"></i>
        </div>
        <main>
            <h1 class="blackcolor">Impressum</h1>
            <hr>
            <p>Dieses Impressum gilt für die Website der Hotelverwaltung:</p>
            <p><strong>Firma:</strong> Serenity Haven</p>
            <p><strong>Adresse:</strong> Höchstädtpl. 6, 1200 Wien</p>
            <p><strong>Telefon:</strong> +43 XXXXX XXXXXX</p>
            <p><strong>E-Mail:</strong>  roman.tisch.serenity@gmail.com</p>
            <p><strong>Firmenbuchnummer (FBN) oder Handelsregisternummer:</strong> FN 123456a</p>
            <p><strong>Umsatzsteuer-Identifikationsnummer (UID):</strong> ATU12345678</p>
            <p><strong>Berufsrechtliche Vorschriften:</strong> Gemäß Hotel- und Gaststättenverordnung</p>
            <p><strong>Kammermitgliedschaft:</strong> Wirtschaftskammer Österreich</p>
            <p><strong>Aufsichtsbehörde:</strong> Magistratisches Bezirksamt Wien</p>
            <p><strong>Bankverbindung:</strong> Musterbank, IBAN: AT611234567890123456</p>
            <p><strong>Haftpflichtversicherung:</strong> Allianz Versicherung, Polizei Nr. 98765432</p>
            <p><strong>Copyright:</strong> Copyright © 2023 Serenity Haven</p>
            <hr>
            <h3>Projektteam</h3>
            <p>Beteiligte Studierende am Projekt:</p>
            <ul>
                <li>Elaine Fink</li>
                <li>Niklas Brandtner</li>
            </ul>
        </main>
        <footer>
            <p>&copy; <?php echo date("Y"); ?> Hotel Webseite</p>
        </footer>
        <script src="https://code.jquery.com/jquery-3.7.1.js" integrity="sha256-eKhayi8LEQwp4NKxN+CfCh+3qOVUtJn3QNZ0TciWLP4=" crossorigin="anonymous"></script>
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ka7Sk0Gln4gmtz2MlQnikT1wXgYsOg+OMhuP+IlRH9sENBO0LRn5q+8nbTov4+1p" crossorigin="anonymous"></script>
    </body>
</html>