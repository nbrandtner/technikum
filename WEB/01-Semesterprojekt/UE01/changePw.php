<?php
session_start();

// Check if the user is logged in
if (!isset($_SESSION['loggedin'])) {
    // User is not logged in. Redirect them to the login page
    header('Location: login.php');
    exit;
}
include 'db_config.php';

// User's data for this example
$id = $_SESSION['u_id'];

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    // Update the user's data based on the form inputs
    $oldpassword = $_POST['oldpassword'];
    $newpassword = $_POST['newpassword'];
    $confirmpassword = $_POST['confirmpassword'];

    // Check if old password is correct
    $checkPasswordStmt = $mysqli->prepare("SELECT * FROM user WHERE u_id = ?");
    $checkPasswordStmt->bind_param("i", $id);
    $checkPasswordStmt->execute();
    $result = $checkPasswordStmt->get_result();
    $user = $result->fetch_assoc();
    $hashed_password = $user['u_pw'];

    // Verify the entered password against the hashed password
    if (!password_verify($oldpassword, $hashed_password)) {
        // Passwords don't match, show an error message
        $_SESSION['message'] = 'Old password is incorrect';
        header('Location: changePw.php');
        exit;
    }
    
    // check the new password isn't the same as the old one
    if (($newpassword==$oldpassword)) {
        // Passwords don't match, show an error message
        $_SESSION['message'] = 'New password must be different from old password';
        header('Location: changePw.php');
        exit;
    }

    $checkPasswordStmt->close();

    if ($newpassword != $confirmpassword) {
        $_SESSION['message'] = 'Passwords do not match';
        header('Location: changePw.php');
        exit;
    }
    // Hash the new password
    $hashed_password = password_hash($newpassword, PASSWORD_DEFAULT);

    // Prepare and execute the update query
    $stmt = $mysqli->prepare("UPDATE user SET u_pw = ? WHERE u_id = ?");
    $stmt->bind_param("si", $hashed_password, $id);

    // Execute the update
    if ($stmt->execute()) {
        // Optionally, redirect the user to a different page after successful update
        $_SESSION['u_id']= $id;
        $_SESSION['message'] = 'Password changed successfully';
        header('Location: profil.php');
        exit;
    } else {
        // Handle the error, if any
        $_SESSION['message'] = 'Could not update password' . $mysqli->error;
    }

    $stmt->close();
    $mysqli->close(); // Close the database connection
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
                <div class="row justify-content-center">
                    <div class ='card'>
                        <div class='cardcontainer'>
                            <form action="changePw.php" method="post">
                                <?php
                                    if(isset($_SESSION['message'])) {
                                        if($_SESSION['message'] == 'Password changed successfully') {
                                            echo '<div class="success-message alert alert-success" role="alert">' . $_SESSION['message'] . '</div>';
                                            unset($_SESSION['message']);
                                        } else {
                                            echo '<div class="error-message alert alert-danger" role="alert">' . $_SESSION['message'] . '</div>';
                                            unset($_SESSION['message']);
                                        }
                                    }
                                ?>
                                <h1 class="blackcolor">Change Password</h1><hr><br>
                                
                                <div class="form-group form-margin">
                                    <input type="password" class="form-control" id="oldpassword" name="oldpassword" placeholder="Old Password" alt="Please enter your old password" required><br>
                                </div>
                                <div class="form-group form-margin">
                                    <input type="password" class="form-control" id="newpassword" name="newpassword" placeholder="New Password" alt="Please enter your new password" required><br>
                                </div>
                                <div class="form-group form-margin">
                                    <input type="password" class="form-control" id="confirmpassword" name="confirmpassword" placeholder="Repeat New Password" alt="Please repeat your new password" required><br>
                                </div>
                                <br>
                                <button name="submit" type="submit" class="btn btn-primary" alt="Back to Homepage">Submit</button>
                                <br>
                            </form>
                        </div>
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
