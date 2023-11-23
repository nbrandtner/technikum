 <!-- Modal für das Profil -->
 <div class="modal fade" id="profilModal" tabindex="-1" role="dialog" aria-labelledby="profilModalLabel" aria-hidden="true">
    <div class="modal-dialog" role="document">
        <div class="modal-content">
            <div class="modal-header">
                <h5 class="modal-title" id="loginModalLabel">Profil</h5>
                <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
            </div>
            <div class="modal-body">
                <!-- Daten des Users-->
                <div class="mb-3">
                    <label class="form-label">Gender:</label>
                    <div class="form-check form-check-inline">
                        <input type="radio" name="radio" id="male" class="form-check-input input" value="male" checked="">
                        <label class="form-check-label mr-3" for="male" alt="male">Male</label>
                    </div>
                    <div class="form-check form-check-inline">
                        <input type="radio" name="radio" id="female" class="form-check-input input" value="female">
                        <label class="form-check-label mr-3" for="female" alt="female">Female</label>
                    </div>
                    <div class="form-check form-check-inline">
                        <input type="radio" name="radio" id="diverse" class="form-check-input input" value="diverse">
                        <label class="form-check-label" for="diverse" alt="diverse">Diverse</label>
                    </div>
                </div>
                <div class="mb-3">
                    <label class="form-label">Firstname:</label>
                    <input type="text" class="form-control" id="registerFirstName" name="registerFirstName" placeholder="Firstname" alt="Your firstname" required>
                </div>
                <div class="mb-3">
                    <label class="form-label">Surname:</label>
                    <input type="text" class="form-control" id="registerLastName" name="registerLastName" placeholder="Surname" alt="Your surname"required>
                </div>
                <div class="mb-3">
                    <label class="form-label">E-Mail:</label>
                    <input type="email" class="form-control" id="registerEmail" name="registerEmail" placeholder="E-Mail" alt="Your E-Mail" required>
                </div>
                <div class="mb-3">
                    <label class="form-label">Username::</label>
                    <input type="text" class="form-control" id="registerUser" name="registerUser" placeholder="Username" alt="Your Username" required>
                </div>
                <br>
                <div class="mb-3">
                    <input type="password" class="form-control" id="registerPassword" name="registerPassword" placeholder="Password" alt="Please enter your password" required>
                </div>
                <div class="mb-3">
                    <input type="password" class="form-control" id="confirmPassword" name="confirmPassword" placeholder="Confirm Password" alt="Please confirm your password" required>
                </div>
            </div>
            <div class="modal-footer">  
                <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Close</button>
                <button type="button" class="btn btn-primary">Edit</button>
            </div>
        </div>
    </div>
</div>
