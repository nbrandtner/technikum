<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-4bw+/aepP/YC94hEpVNVgiZdgIC5+VKNBQNGCHeKRQN+PtmoHDEXuppvnDJzQIu9" crossorigin="anonymous">
        <title>Serenity Haven - Room Reservation</title>
        <!-- Füge hier deine CSS-Dateien hinzu, um das Styling anzupassen -->
        <link rel="stylesheet" href="../style.css">
    </head>
    <body>
        <?php 
            include '../modal/login.php'; 
            include '../modal/profil.php';
            include '../modal/register.php';
        ?>
        <!--Hier ist ein eigener Header-->
        <nav class="top-nav">
            <button type="button" href="profil.php"class="glow-on-hover upper-corner" data-bs-toggle="modal" data-bs-target="#profilModal">Profil</button>
            <button type="button" href="register.php"class="glow-on-hover upper-corner" data-bs-toggle="modal" data-bs-target="#registerModal">Register</button>
            <button type="button" href="login.php"class="glow-on-hover upper-corner" data-bs-toggle="modal" data-bs-target="#loginModal">Login</button>
        </nav>
        <header>
            <img src="../img/logo-transparent.png" width="330px">
            <nav>
                <button onclick="window.location.href='reservation.php'" type="button" href="reservation.php" class="glow-on-hover" alt="Reservation">Reservation</button>              
                <button onclick="window.location.href='../index.php'" type="button" href="../index.php"class="glow-on-hover" alt="Homepage">Homepage</button>
                <button onclick="window.location.href='../help.php'" type="button" href="../help.php"class="glow-on-hover" alt="Help/FAQ">Help/FAQs</button>
                <button onclick="window.location.href='../impressum.php'" type="button" href="../impressum.php"class="glow-on-hover" alt="Impressum">Impressum</button>
                <!-- Weitere Navigationslinks für angemeldete Benutzer -->
            </nav>
        </header>
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
            <h1 class="blackcolor">Room Reservation</h1>
            <hr>
            </br>
            <h2 class="blackcolor" style="text-align:left;">Your Reservations</h2>
            <p>Wir haben leider keine aktuellen Room Reservations gefunden. Wir freuen uns auf deinen nächsten Besuch bei Serenity Haven!</p> </br>
            <hr>
            </br>
            <h2 class="blackcolor" >Unsere Zimmeroptionen</h2>
            </br>
            <div class ="card">
                <img class="cardimg" src="../img/deluxe.jpg">
                <div class="cardcontainer">
                    <h4>Deluxe Room</h4>
                    <button type="button" class="btn btn-primary" style="margin-left: 90%;" data-bs-dismiss="modal">Book</button>
                </div>
            </div></br>
            <div class ="card">
                <img class="cardimg" src="../img/junior-suite.png">
                <div class="cardcontainer">
                    <h4>Junior Suite</h4>
                    <button type="button" class="btn btn-primary" style="margin-left: 90%;" data-bs-dismiss="modal">Book</button>
                 </div>
            </div></br>
            <div class ="card">
                <img class="cardimg" src="../img/mastersuite.jpg">
                <div class="cardcontainer">
                    <h4>Master Suite</h4>
                    <button type="button" class="btn btn-primary" style="margin-left: 90%;" data-bs-dismiss="modal">Book</button>
                </div>
            </div></br>
            <div class ="card">
                <img class="cardimg" src="../img/penthouse-suite.jpg">
                <div class="cardcontainer">
                    <h4>Penthouse Suite</h4>
                    <button type="button" class="btn btn-primary" style="margin-left: 90%;" data-bs-dismiss="modal">Book</button>
                </div>
            </div>
        </main>
        <footer>
            <p>&copy; <?php echo date("Y"); ?> Hotel Webseite</p>
        </footer>
        <script src="https://code.jquery.com/jquery-3.7.1.js" integrity="sha256-eKhayi8LEQwp4NKxN+CfCh+3qOVUtJn3QNZ0TciWLP4=" crossorigin="anonymous"></script>
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ka7Sk0Gln4gmtz2MlQnikT1wXgYsOg+OMhuP+IlRH9sENBO0LRn5q+8nbTov4+1p" crossorigin="anonymous"></script>
    </body>
</html>