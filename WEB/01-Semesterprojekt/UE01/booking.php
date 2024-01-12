<?php
// Start the session
session_start();
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    
}
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
            <h1 class="blackcolor">Book your room</h1>
            <?php if(isset($_SESSION['loggedin'])): ?>
                <form action="<?php echo $_SERVER["PHP_SELF"];?>" method="post" class="col-md-12">
                    <div class="form-group">
                        <div class ='card'>
                            <img class='cardimg' src='img/deluxe.jpg'>
                            <div class='cardcontainer'>
                                <div class="form-check form-check-inline">
                                    <input type="radio" name="rooms" id="delux" class="form-check-input input" value="delux" checked="">
                                    <label  for="delux" class="form-check-label mr-3">Deluxe Room</label>
                                </div>
                            </div>
                        </div><br>
                        <div class ='card'>
                            <img class='cardimg' src="img/junior-suite.png">
                            <div class='cardcontainer'>
                                <div class="form-check form-check-inline">
                                    <input type="radio" name="rooms" id="junior" class="form-check-input input" value="junior" checked="">
                                    <label  for="junior" class="form-check-label mr-3">Junior Suite</label>
                                </div>
                            </div>
                        </div><br>
                        <div class ='card'>
                            <img class='cardimg' src="img/mastersuite.jpg">
                            <div class='cardcontainer'>
                                <div class="form-check form-check-inline">
                                    <input type="radio" name="rooms" id="master" class="form-check-input input" value="master" checked="">
                                    <label  for="master" class="form-check-label mr-3">Master Suite</label>
                                </div>
                            </div>
                        </div><br>
                        <div class ='card'>
                            <img class='cardimg' src="img/penthouse-suite.jpg">
                            <div class='cardcontainer'>
                                <div class="form-check form-check-inline">
                                    <input type="radio" name="rooms" id="pent" class="form-check-input input" value="pent" checked="">
                                    <label  for="pent" class="form-check-label mr-3">Penthouse Suite</label>
                                </div>
                            </div>
                        </div><br>
                    </div><hr><br>
                    <div>
                        <h5>In welchem Zeitraum willst du das Zimmer buchen?</h5>
                            <label for="from" >Von</label>
                            <input type="date" id="from"  placeholder="from">
                            <label for="to" >Bis</label>
                            <input type="date" id="to"  placeholder="to">
                    </div><br><hr><br>
                    <div>
                        <h5>Extra options:</h5 >
                        <div class="form-check form-check-inline">
                            <input type="checkbox" id="food" class="form-check-input input" placeholder="Frühstück">
                            <label for="food" class="form-check-label mr-3">Frühstück</label><br>
                        </div>
                        <div class="form-check form-check-inline">
                            <input type="checkbox" id="parking" class="form-check-input input" placeholder="Parkplatz">
                            <label for="parking" class="form-check-label mr-3">Parkplatz</label><br>
                        </div>
                        <div class="form-check form-check-inline">
                            <input type="checkbox" id="pet" class="form-check-input input" placeholder="Haustiere">
                            <label for="pet" class="form-check-label mr-3">Haustiere mitnehmen</label><br>
                        </div>
                    </div>
                    <button type="submit" name="submit" class="btn btn-primary">Book -> Checkout</button><br>
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