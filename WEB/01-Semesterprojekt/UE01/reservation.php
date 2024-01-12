<?php
// Start the session
session_start();
?>
<!DOCTYPE html>
<html lang="en">
    <?php include 'htmlhead.php'; ?>
    <body>
        <?php
            include 'header.php';
        ?>
        <div class="icon-container">
        <main>
            <h1 class="blackcolor">Room Reservation</h1>
            <hr>
            </br>
            <?php if(isset($_SESSION['loggedin'])): ?>
                <h2 class="blackcolor" style="text-align:left;">Your Reservations</h2>
                <p>Wir haben leider keine aktuellen Room Reservations gefunden. Wir freuen uns auf deinen nächsten Besuch bei Serenity Haven!</p> </br>
                <button type="button" class="btn btn-primary" onclick="window.location.href='booking.php'" data-bs-dismiss="modal">Book your room</button>
                <hr>
                </br>
            <?php else: ?>
                <p>Du bist nicht <a onclick="window.location.href='login.php'" class="glow-on-hover" >angemeldet</a>. Bitter melde dich an oder <a onclick="window.location.href='register.php'" class="glow-on-hover" >erstelle ein Konto</a> um einen Raum zu reservieren.</p>
            <?php endif; ?>
        </main>
        <footer>
            <p>&copy; <?php echo date("Y"); ?> Hotel Webseite</p>
        </footer>
        <script src="https://code.jquery.com/jquery-3.7.1.js" integrity="sha256-eKhayi8LEQwp4NKxN+CfCh+3qOVUtJn3QNZ0TciWLP4=" crossorigin="anonymous"></script>
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ka7Sk0Gln4gmtz2MlQnikT1wXgYsOg+OMhuP+IlRH9sENBO0LRn5q+8nbTov4+1p" crossorigin="anonymous"></script>
    </body>
</html>