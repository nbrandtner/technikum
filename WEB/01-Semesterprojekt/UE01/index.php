<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-4bw+/aepP/YC94hEpVNVgiZdgIC5+VKNBQNGCHeKRQN+PtmoHDEXuppvnDJzQIu9" crossorigin="anonymous">
        <title>Serenity Haven</title>
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
            <h1 class="blackcolor">Welcome to Serenity Haven!</h1>
            <hr>
            <form enctype="multipart/form-data" method="post" action="fileupload.php">
                <input type="file" name="fileToUpload" id="fileToUpload">
                <input type="submit" value="Hochladen" name ="submit">
            </form>
            <br>
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