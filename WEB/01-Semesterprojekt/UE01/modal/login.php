<!-- Modal für Anmeldung -->
<div class="modal fade" id="loginModal" tabindex="-1" role="dialog" aria-labelledby="loginModalLabel" aria-hidden="true">
    <div class="modal-dialog" role="document">
        <div class="modal-content">
            <div class="modal-header">
                <h5 class="modal-title" id="loginModalLabel">Login</h5>
                <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
            </div>
            <div class="modal-body">
                <!-- Anmeldeformularfelder hier -->
                <!-- Beispiel: E-Mail und Passwort -->
                <div class="mb-3">
                    <input type="email" class="form-control" id="loginEmail" name="loginEmail" placeholder="E-Mail" alt="Please enter your E-Mail" required>
                </div>
                <div class="mb-3">
                    <input type="password" class="form-control" id="loginPW" name="loginPW" placeholder="Password" alt="Please enter your password" required>
                </div>
                <!-- Weitere Anmeldeformularfelder hier -->
            </div>
            <div class="modal-footer">  
                <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Close</button>
                <button type="button" class="btn btn-primary">Login</button>
            </div>
        </div>
    </div>
</div>