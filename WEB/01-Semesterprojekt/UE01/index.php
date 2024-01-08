<?php
// Start the session
session_start();
?>
<!DOCTYPE html>
<html lang="en">
    <?php include 'htmlhead.php'; ?>
    <body>   
        <?php include 'header.php'; ?>
        <div class="icon-container">
        <main>
            <h1 class="blackcolor">Welcome to Serenity Haven!</h1>
            <?php if(isset($_SESSION['loggedin']) && $_SESSION['role'] == "admin"): ?>
                <hr>
                <br>
                <form enctype="multipart/form-data" method="post" action="fileupload.php">
                    <input type="file" name="fileToUpload"  id="fileToUpload">
                    <input type="submit" value="Hochladen" name ="submit">
                </form>
                <br>
            <?php endif; ?> 
            <hr>
            <div class ="card">
                <img class="cardimg" src="img/rose_wine.jpg">
                <div class="cardcontainer">
                    <h4>Book your room hourly!</h4>
                    <p>Ab jetzt können Sie unsere Zimmer auch stündlich buchen.</p>
                </div>
            </div></br>
            <div class ="card">
                <img class="cardimg" src="img/massage.png">
                <div class="cardcontainer">
                    <h4>Enjoy our aroma oil massage!</h4>
                    <p>Im SPA bereich können sie sich von augebildenen Masseuren verwöhnen lassen. Dieses Service ist ab einem Aufenthalt von 2 Nächten inklusive.</p>
                </div>
            </div></br>
            <div class ="card">
                <img class="cardimg" src="img/whirlpool.jpg">
                <div class="cardcontainer">
                    <h4>New whirlpool in our honeymoon suits!</h4>
                </div>
            </div>
        </main>
        <footer>
            <p>&copy; <?php echo date("Y"); ?> Hotel Website</p>
        </footer>
        <script src="https://code.jquery.com/jquery-3.7.1.js" integrity="sha256-eKhayi8LEQwp4NKxN+CfCh+3qOVUtJn3QNZ0TciWLP4=" crossorigin="anonymous"></script>
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ka7Sk0Gln4gmtz2MlQnikT1wXgYsOg+OMhuP+IlRH9sENBO0LRn5q+8nbTov4+1p" crossorigin="anonymous"></script>
    </body>
</html>