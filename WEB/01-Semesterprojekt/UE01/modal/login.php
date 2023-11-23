<!-- Modal für Anmeldung -->
<?php
if(session_status() === PHP_SESSION_NONE) {
    session_start();
}
if(isset($_POST['submit'])) {
    $user = $_POST['loginUser'];
    $password = $_POST['loginPW'];
    
    // Überprüfung des Passworts
    if ($user == 'test' && $password == 'test') {
        $_SESSION['user'] = $user;
        header('Location: index.php'); // Redirect to the index page
        exit;
    } else {
        $errorMessage = "E-Mail oder Passwort war ungültig<br>";
    }
}
?>
<div class="modal fade" id="loginModal" tabindex="-1" role="dialog" aria-labelledby="loginModalLabel" aria-hidden="true">
    <div class="modal-dialog" role="document">
        <div class="modal-content">
            <form action="<?php echo $_SERVER["PHP_SELF"];?>" method="post">
            <div class="modal-header">
                <h5 class="modal-title" id="loginModalLabel">Login</h5>
                <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
            </div>
            <div class="modal-body">
                
                <!-- Anmeldeformularfelder hier -->
                <!-- Beispiel: Username und Passwort -->
                <div class="mb-3">
                    <input type="text" class="form-control" id="loginUser" name="loginUser" placeholder="Username" alt="Please enter your Username" required>
                </div>
                <div class="mb-3">
                    <input type="password" class="form-control" id="loginPW" name="loginPW" placeholder="Password" alt="Please enter your Password" required>
                </div>
                <!-- Weitere Anmeldeformularfelder hier -->
            </div>
            <div class="modal-footer">  
                <button type="button" name="submit" class="btn btn-secondary" data-bs-dismiss="modal">Close</button>
                <button type="submit" class="btn btn-primary">Login</button>
            </div>
        </form>
        </div>
    </div>
</div>
