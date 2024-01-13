<?php
// Start the session

include 'db_config.php';

// define variables and set to empty values
$room = $pet = $food = $parking = $price = "";

session_start();
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $room = test_input($_POST["rooms"]);
    $pet =  check_checkbox("pet");
    $food =  check_checkbox("food");
    $parking =  check_checkbox("parking");

    // Check if all fields are filled (date inputs)
    if(empty($_POST["from"]) ||empty($_POST["to"])){
        $_SESSION['message'] = 'All fields must be filled out';
    }else{
        //Berechnung des Preises
        $price = 0.00;

        //Zimmerpreis berechnen
        if($room == "Delux"){
            $price += 229.00;
            $_SESSION['img'] = 'deluxe.jpg';
        }
        elseif($room == "Junior"){
            $price += 279.00;
            $_SESSION['img'] = 'junior-suite.png';
        } 
        elseif($room == "Master"){ 
            $price += 329.00;
            $_SESSION['img'] = 'mastersuite.jpg';
        }
        elseif($room == "Penthouse"){
            $price += 429.00;
            $_SESSION['img'] = 'penthouse-suite.jpg';
        }

        //Extras berechnen
        if($pet==1) $price+=20.00;
        if($food==1) $price+=30.00;
        if($parking==1) $price+=20.00;

        //Preis mit dauer multiplizieren
        $from = new DateTime($_POST['from']);
        $to = new DateTime($_POST['to']);
        $days = $to->diff($from)->format('%a');
        $price = $price *$days;

        $_SESSION['price'] = $price;
        $_SESSION['room'] = $room;
        $_SESSION['from'] = $_POST["from"];
        $_SESSION['days'] = $days;
        $_SESSION['to'] = $_POST["to"];
        header("Location: checkout.php");
    }
}

//Gibt den Wert der Checkboxen zurück
function check_checkbox($data){
    if(isset($_POST[$data])){
        $_SESSION[$data] = 1;
        return 1;
    } else{
        $_SESSION[$data] = 0;
        return 0;
    }
    
}

function test_input($data)
{
    global $mysqli;
    $data = trim($data);
    $data = stripslashes($data);
    $data = htmlspecialchars($data);
    return $data;
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
            <h1 class="blackcolor">Book your room</h1>
            <?php if(isset($_SESSION['loggedin'])): ?>
                <form action="<?php echo $_SERVER["PHP_SELF"];?>" method="post" class="col-md-12">
                    <div class="form-group">
                        <div class ='card'>
                            <img class='cardimg' src='img/deluxe.jpg'>
                            <div class='cardcontainer'>
                                <div class="form-check form-check-inline">
                                    <input type="radio" name="rooms" id="delux" class="form-check-input input" value="Delux" checked="">
                                    <label  for="delux" class="form-check-label mr-3">Deluxe Suite - 229,00 € / Nacht</label>
                                </div>
                            </div>
                        </div><br>
                        <div class ='card'>
                            <img class='cardimg' src="img/junior-suite.png">
                            <div class='cardcontainer'>
                                <div class="form-check form-check-inline">
                                    <input type="radio" name="rooms" id="junior" class="form-check-input input" value="Junior" checked="">
                                    <label  for="junior" class="form-check-label mr-3">Junior Suite - 279,00 € / Nacht</label>
                                </div>
                            </div>
                        </div><br>
                        <div class ='card'>
                            <img class='cardimg' src="img/mastersuite.jpg">
                            <div class='cardcontainer'>
                                <div class="form-check form-check-inline">
                                    <input type="radio" name="rooms" id="master" class="form-check-input input" value="Master" checked="">
                                    <label  for="master" class="form-check-label mr-3">Master Suite - 329,00 € / Nacht</label>
                                </div>
                            </div>
                        </div><br>
                        <div class ='card'>
                            <img class='cardimg' src="img/penthouse-suite.jpg">
                            <div class='cardcontainer'>
                                <div class="form-check form-check-inline">
                                    <input type="radio" name="rooms" id="penthouse" class="form-check-input input" value="Penthouse">
                                    <label  for="penthouse" class="form-check-label mr-3">Penthouse Suite - 429,00 € / Nacht</label>
                                </div>
                            </div>
                        </div><br>
                    </div><hr><br>
                    <?php
                                if(isset($_SESSION['message'])) {
                                    if($_SESSION['message'] == 'Registration successful') {
                                        echo '<div class="success-message alert alert-success" role="alert">' . $_SESSION['message'] . '</div>';
                                        unset($_SESSION['message']);
                                    } else {
                                        echo '<div class="error-message alert alert-danger" role="alert">' . $_SESSION['message'] . '</div>';
                                        unset($_SESSION['message']);
                                    }
                                }
                                ?>
                    <div>
                        <h5>In welchem Zeitraum willst du das Zimmer buchen?</h5>
                        <label for="from"  >Von</label>
                        <input type="date" name="from" id="from" require>
                        <label for="to" >Bis</label>
                        <input type="date" name="to" id="to" require>
                    </div><br><br><hr><br>
                    <div>
                        <h5>Extra options:</h5 >
                        <div class="form-check form-check-inline">
                            <input type="checkbox" id="food" name="food" class="form-check-input input" placeholder="Frühstück">
                            <label for="food" class="form-check-label mr-3">Frühstück - 30,00 € / Nacht</label><br>
                        </div>
                        <div class="form-check form-check-inline">
                            <input type="checkbox" id="parking" name="parking" class="form-check-input input" placeholder="Parkplatz">
                            <label for="parking" class="form-check-label mr-3">Parkplatz - 20,00 € / Nacht</label><br>
                        </div>
                        <div class="form-check form-check-inline">
                            <input type="checkbox" id="pet" name="pet" class="form-check-input input" placeholder="Haustiere">
                            <label for="pet" class="form-check-label mr-3">Haustiere mitnehmen - 20,00€ / Nacht</label><br>
                        </div>
                    </div>
                    <button type="submit" name="submit" class="btn btn btn-outline-primary">Weiter -> Checkout</button>
                    <button onclick="window.location.href='index.php'" type="button" href="reservation.php"class="btn btn-outline-danger"> x Close</button><br>
                            
                </form>
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