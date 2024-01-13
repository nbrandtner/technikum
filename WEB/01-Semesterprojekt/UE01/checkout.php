<?php
session_start();
// User's data for this example
$room = $_SESSION['room'];
$price = $_SESSION['price'];
$days = $_SESSION['days'];
$from = $_SESSION['from'];#
$to = $_SESSION['to'];
$food = $_SESSION['food'];
$pet = $_SESSION['pet'];
$parking = $_SESSION['parking'];
$status = "neu";
$booked = date('Y-m-d h:i', time());
$user = $_SESSION['u_id'];
$img = $_SESSION['img'];

include 'db_config.php';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Database conection insert reservation
    $stmt = $mysqli->prepare("INSERT INTO reservation (r_room, r_status, r_booked, r_from, r_to, r_user, r_food, r_pet, r_parking, r_price) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
    $stmt->bind_param("ssssssssss", $room, $status, $booked, $from, $to, $user, $food, $pet, $parking, $price);
    $stmt->execute();
    $stmt->close();

    $_SESSION['message'] = 'Reservation successful';
    header("Location: reservation.php");
}

?>
<!DOCTYPE html>
<html lang="en">
    <?php include 'htmlhead.php'; ?>
    <body>
        <?php
          include 'header.php';
        ?>
        <main>
            <h1 class="blackcolor">Checkout</h1><hr><br>
            <div>
            <?php if(isset($_SESSION['loggedin'])): ?>
            <form action="<?php echo $_SERVER["PHP_SELF"];?>" method="post" class="col-md-12">
                <button onclick="window.location.href='booking.php'" type="button" href="booking.php"class="btn btn-outline-primary"> <- Back</button><br><br>
                <div class ='card'>
                        <img class='cardimg' src="img/<?php echo $img; ?>">
                        <div class='cardcontainer'>
                            <div class="form-check form-check-inline">
                                <h5><?php echo $room; ?> Suite</h5>
                                <br>
                                <p>Vom <?php echo $from; ?> bis zum <?php echo $to; ?></p>
                                <p><?php echo $price; ?>€ (für <?php echo $days; ?> Übernachtungen)</p>
                                <br>
                            </div>                            
                        </div>
                </div><br>

                <button type="submit" name="submit" class="btn btn-outline-primary">Zahlungspflichtig buchen</button>
                <button onclick="window.location.href='index.php'" type="button" href="reservation.php"class="btn btn-outline-danger"> x Close</button><br>
            </form>

            </div>
            <?php else: ?>
                <p>Du bist nicht <a onclick="window.location.href='login.php'" class="glow-on-hover">angemeldet</a>. Bitter melde dich an oder <a onclick="window.location.href='register.php'" class="glow-on-hover">erstelle ein Konto</a> um einen Raum zu reservieren.</p>
            <?php endif; ?>
        </main>         
        <footer>
            <p>&copy; <?php echo date("Y"); ?> Hotel Webseite</p>
        </footer>
        <script src="https://code.jquery.com/jquery-3.7.1.js" integrity="sha256-eKhayi8LEQwp4NKxN+CfCh+3qOVUtJn3QNZ0TciWLP4=" crossorigin="anonymous"></script>
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ka7Sk0Gln4gmtz2MlQnikT1wXgYsOg+OMhuP+IlRH9sENBO0LRn5q+8nbTov4+1p" crossorigin="anonymous"></script>
    </body>
</html>