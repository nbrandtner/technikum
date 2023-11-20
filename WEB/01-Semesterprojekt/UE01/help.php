<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-4bw+/aepP/YC94hEpVNVgiZdgIC5+VKNBQNGCHeKRQN+PtmoHDEXuppvnDJzQIu9" crossorigin="anonymous">
        <title>Serenity Haven - Hilfe / FAQs</title>
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
            <h1 class="blackcolor">Hilfe / FAQs</h1>
            <hr>
            </br>
            <p><strong>Frage 1:</strong> Wie kann ich ein Zimmer reservieren?</p>
            <p><strong>Antwort:</strong> Um ein Zimmer zu reservieren, müssen Sie sich zuerst registrieren und dann auf die Reservierungsseite gehen.</p>
            </br>
            <p><strong>Frage 2:</strong> Kann ich mein Profil bearbeiten?</p>
            <p><strong>Antwort:</strong> Ja, nachdem Sie sich angemeldet haben, können Sie Ihr Profil bearbeiten, um Ihre Stammdaten zu ändern.</p>
            </br>
            <!-- Füge weitere FAQs hinzu -->
            <p>Wenn Sie weitere Fragen haben, können Sie uns jederzeit über das Kontaktformular erreichen.</p>
        </main>
        <footer>
            <p>&copy; <?php echo date("Y"); ?> Hotel Webseite</p>
        </footer>
        <script src="https://code.jquery.com/jquery-3.7.1.js" integrity="sha256-eKhayi8LEQwp4NKxN+CfCh+3qOVUtJn3QNZ0TciWLP4=" crossorigin="anonymous"></script>
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ka7Sk0Gln4gmtz2MlQnikT1wXgYsOg+OMhuP+IlRH9sENBO0LRn5q+8nbTov4+1p" crossorigin="anonymous"></script>
    </body>
</html>