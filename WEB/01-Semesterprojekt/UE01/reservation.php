<!DOCTYPE html>
<html lang="en">
    <?php include 'htmlhead.php'; ?>
    <body>
        <?php 
            include 'profil.php';
            include 'register.php';
        ?>
        <?php
            include 'header.php';
        ?>
        <div class="icon-container">
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
                <img class="cardimg" src="img/deluxe.jpg">
                <div class="cardcontainer">
                    <h4>Deluxe Room</h4>
                    <button type="button" class="btn btn-primary" style="margin-left: 90%;" data-bs-dismiss="modal">Book</button>
                </div>
            </div></br>
            <div class ="card">
                <img class="cardimg" src="img/junior-suite.png">
                <div class="cardcontainer">
                    <h4>Junior Suite</h4>
                    <button type="button" class="btn btn-primary" style="margin-left: 90%;" data-bs-dismiss="modal">Book</button>
                 </div>
            </div></br>
            <div class ="card">
                <img class="cardimg" src="img/mastersuite.jpg">
                <div class="cardcontainer">
                    <h4>Master Suite</h4>
                    <button type="button" class="btn btn-primary" style="margin-left: 90%;" data-bs-dismiss="modal">Book</button>
                </div>
            </div></br>
            <div class ="card">
                <img class="cardimg" src="img/penthouse-suite.jpg">
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