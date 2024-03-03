<?php
session_start();
include 'db_config.php';

// Check if the user is logged in
if (!isset($_SESSION['loggedin'])) {
    // User is not logged in. Redirect them to the login page
    header('Location: login.php');
    exit;
}

// User's data for this example
$role = $_SESSION['u_role'];
$username = $_SESSION['u_username'];

if ($role != "admin") { // check if user is admin
    $_SESSION['message'] = 'Please Login as Admin to access this page';
    header("Location: profil.php");
}

// Handle form submission
if (isset($_POST['submit'])) {
	include 'db_config.php';
    // Validate form fields
    if (
        empty($_POST['username']) ||
        empty($_POST['usersVorname']) ||
        empty($_POST['usersNachname']) ||
        empty($_POST['gender']) ||
        empty($_POST['usersEmail']) ||
        empty($_POST['role']) ||
        empty($_POST['isActive'])
    ) {
		$_SESSION['message'] = 'All fields are required. Please fill in all the fields.';
    }

    // Retrieve data from the form
    $userId = $_POST['usersId'];
    $newUsername = $_POST['username'];
    $newFirstName = $_POST['usersVorname'];
    $newLastName = $_POST['usersNachname'];
    $newGender = $_POST['gender'];
    $newEmail = $_POST['usersEmail'];
    $newRole = $_POST['role'];
    $newStatus = $_POST['isActive'];

	if ($newGender == "male") {
        $newTitle = "Mr.";
    } elseif ($newGender == "female") {
        $newTitle = "Mrs.";
    } elseif ($newGender == "diverse") {
        $newTitle = "Mx.";
    }

    // Update the database using prepared statements
    $updateSql = "UPDATE `user` SET
        `u_username` = ?,
        `u_firstname` = ?,
        `u_lastname` = ?,
        `u_gender` = ?,
        `u_email` = ?,
        `u_status` = ?,
		`u_title` = ?,
		`u_role` = ?	
        WHERE `u_id` = ?";

    $stmt = $mysqli->prepare($updateSql);
    $stmt->bind_param('sssssisss', $newUsername, $newFirstName, $newLastName, $newGender, $newEmail, $newStatus, $newTitle, $newRole, $userId);

    if ($stmt->execute()) {
		$_SESSION['message'] = 'Record updated successfully';
		header("Location: user_list.php");
    } else {
		$_SESSION['message'] = 'Error updating record:'  . $stmt->error;
    }

    $stmt->close();
	unset($_POST['submit']);
	exit();
}

?>
<!DOCTYPE html>
<html lang="en">
    <?php include 'htmlhead.php'; ?>
    <body>
        <?php include 'header.php';?>
        <main>
			<div class="row justify-content-center">
			<?php
				if(isset($_SESSION['message'])) {
					if($_SESSION['message'] == 'Record updated successfully') {
						echo '<div class="success-message alert alert-success" role="alert">' . $_SESSION['message'] . '</div>';
						unset($_SESSION['message']);
					} else {
						echo '<div class="error-message alert alert-danger" role="alert">' . $_SESSION['message'] . '</div>';
						unset($_SESSION['message']);
					}
				}
            ?>
				<h1 class="blackcolor">User Management for Admins!</h1><hr><br>
				<h2>List of Registered Users <small class="text-muted fs-6">(only edit one user at a time)</small></h2>
				<table class="table-custom table-bordered table mt-3">
					<thead>
						<tr>
							<th scope="col" style="width: 6%;">ID</th>
							<th scope="col" style="width: 14%;">Username</th>
							<th scope="col" style="width: 13%;">First Name</th>
							<th scope="col" style="width: 13%;">Last Name</th>
							<th scope="col" style="width: 12%;">Gender</th>
							<th scope="col" style="width: 18%;">Email</th>
							<th scope="col" style="width: 11%;">Role</th>
							<th scope="col" style="width: 15%;">Status</th>
							<th scope="col" style="width: 5%;"></th>
						</tr>
					</thead>
					<tbody> 
						<?php
							if (empty(mysqli_connect_error())) { //no db error
							{
								$sql = "SELECT `u_id`,`u_firstname`,`u_lastname`,`u_gender`,`u_status`,`u_email`,`u_username`,`u_role` FROM `user` WHERE `u_role`!=\"admin\";";
								$result2 = $mysqli->query($sql);

								if ($result2->num_rows > 0) {
								while ($row = $result2->fetch_assoc()) {
						?>
						<tr>
							<form style="border-radius:30%" method="POST" action="">
								<td>
									<input type="text" name="usersId" id="usersId" value="<?php echo $row['u_id']; ?>" class="form-control" readonly>
								</td>
								<td>
									<input type="text" name="username" id="username" value="<?php echo $row['u_username']; ?>" class="form-control">
								</td>
								<td>
									<input type="text" name="usersVorname" id="usersVorname" value="<?php echo $row['u_firstname']; ?>" class="form-control">
								</td>
								<td>
									<input type="text" name="usersNachname" id="usersNachname" value="<?php echo $row['u_lastname']; ?>" class="form-control">
								</td>
								<td>
									<div class="form-group">
										<div class="form-check form-check-inline">
											<input type="radio" name="gender" id="male" class="form-check-input input" value="male" <?php echo ($row['u_gender'] === 'male') ? 'checked' : ''; ?>>
											<label class="form-check-label mr-3" for="male" alt="male">Male</label>
										</div>
										<div class="form-check form-check-inline">
											<input type="radio" name="gender" id="female" class="form-check-input input" value="female" <?php echo ($row['u_gender'] === 'female') ? 'checked' : ''; ?>>
											<label class="form-check-label mr-3" for="female" alt="female">Female</label>
										</div>
										<div class="form-check form-check-inline">
											<input type="radio" name="gender" id="diverse" class="form-check-input input" value="diverse" <?php echo ($row['u_gender'] === 'diverse') ? 'checked' : ''; ?>>
											<label class="form-check-label" for="diverse" alt="diverse">Diverse</label>
										</div>
									</div>										
								</td>
								<td>
									<input type="email" name="usersEmail" id="usersEmail" value="<?php echo $row['u_email']; ?>" class="form-control">
								</td>
								<td>
									<div class="form-group">
										<div class="form-check form-check-inline">
											<input type="radio" name="role" id="user" class="form-check-input input" value="user" <?php echo ($row['u_role'] === 'user') ? 'checked' : ''; ?>>
											<label class="form-check-label mr-3" for="user" alt="user">User</label>
										</div>
										<div class="form-check form-check-inline">
											<input type="radio" name="role" id="admin" class="form-check-input input" value="admin" <?php echo ($row['u_role'] === 'admin') ? 'checked' : ''; ?>>
											<label class="form-check-label mr-3" for="admin" alt="admin">Admin</label>
										</div>
									</div>
								</td>
								<td>
									<div class="form-group">
										<div class="form-check form-check-inline">
											<input type="radio" name="isActive" id="active" class="form-check-input input" value="1" <?php echo ($row['u_status'] == 1) ? 'checked' : ''; ?>>
											<label class="form-check-label mr-3" for="active" alt="active">Active</label>
										</div>
										<div class="form-check form-check-inline">
											<input type="radio" name="isActive" id="inactive" class="form-check-input input" value="0" <?php echo ($row['u_status'] == 0) ? 'checked' : ''; ?>>
											<label class="form-check-label mr-3" for="inactive" alt="inactive">Inactive</label>
										</div>
									</div>
								</td>
								<td>
									<button type="submit" name="submit" class="btn btn-outline-primary">Save</button>
								</td>
							</form>
						</tr>
						<?php
									}
									} else {
									echo "No users found";
									}
								}
								} else {
								echo "Error connecting to database: " . mysqli_connect_error();
								}
						?>
					</tbody>
				</table>
			</div>
		</main>
        <footer>
            <p>&copy; <?php echo date("Y"); ?> Hotel Website</p>
        </footer>
        <script src="https://code.jquery.com/jquery-3.7.1.js" integrity="sha256-eKhayi8LEQwp4NKxN+CfCh+3qOVUtJn3QNZ0TciWLP4=" crossorigin="anonymous"></script>
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ka7Sk0Gln4gmtz2MlQnikT1wXgYsOg+OMhuP+IlRH9sENBO0LRn5q+8nbTov4+1p" crossorigin="anonymous"></script>
    </body>
</html>