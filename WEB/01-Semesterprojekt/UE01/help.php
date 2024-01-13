<!DOCTYPE html>
<html lang="en">

<?php include 'htmlhead.php'; 
// Start the session
        session_start();
        ?>
<body>
    <?php
        include 'header.php';
    ?>
    <main>
        <h1 class="blackcolor">Hilfe / FAQs</h1>
        <hr>
        <br>
        <div class="row justify-content-center">
            <div class="col-md-6">
                <section class="faq-section">
                    <div class="accordion" id="faqAccordion">
                        <div class="faq-item">
                            <div class="accordion-item">
                                <h2 class="faq-question accordion-button" data-bs-toggle="collapse" data-bs-target="#faq1" aria-expanded="true" aria-controls="faq1">
                                    Wie kann ich meine Buchung einsehen?
                                </h2>
                            </div>
                            <div id="faq1" class="collapse faq-answer-box">
                                <div class="faq-answer">
                                    <p>Sie können Ihre Buchung einsehen, indem Sie von der Homepage aus auf 'Book your room' klicken. Nun sind Sie auf unserer Reservierungsseite auf welcher Ihnen auch Ihre Buchung angezeigt wird.</p>
                                </div>
                            </div>
                        </div>
                        <div class="faq-item">
                            <div class="accordion-item">
                                <h2 class="faq-question accordion-button" data-bs-toggle="collapse" data-bs-target="#faq2" aria-expanded="true" aria-controls="faq2">
                                    Gibt es Parkmöglichkeiten am Hotel?
                                </h2>
                            </div>
                            <div id="faq2" class="collapse faq-answer-box">
                                <div class="faq-answer ">
                                    <p>Ja, unser Hotel verfügt über Parkplätze für Gäste welche beim Buchen dazubestellt werden können.</p>
                                </div>
                            </div>
                        </div>
<<<<<<< HEAD
                        <div class="faq-item">
                            <div class="accordion-item">
                                <h2 class="faq-question accordion-button" data-bs-toggle="collapse" data-bs-target="#faq3"aria-expanded="true" aria-controls="faq3">
                                    Wie kann ich mein Passwort ändern?
                                </h2>
                            </div>
                            <div id="faq3" class="collapse faq-answer-box">
                                <div class="faq-answer">
                                    <p>Sie können ihr Passwort sowie andere Kontodaten in Ihrem Profil ändern</p>
                                </div>
=======
                        <div id="faq3" class="collapse faq-answer-box">
                            <div class="faq-answer ">
                                <p>Sie können ihr Passwort sowie andere Kontodaten in Ihrem Profil ändern</p>
>>>>>>> 40d51b2feb50eec0efcaa24e1a81ec59d64fb3cb
                            </div>
                        </div>
                    </div>
                </section>
            </div>
        </div>
    </main>
    <footer>
        <p>&copy; <?php echo date("Y"); ?> Hotel Webseite</p>
    </footer>
    <script src="https://code.jquery.com/jquery-3.7.1.js" integrity="sha256-eKhayi8LEQwp4NKxN+CfCh+3qOVUtJn3QNZ0TciWLP4=" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ka7Sk0Gln4gmtz2MlQnikT1wXgYsOg+OMhuP+IlRH9sENBO0LRn5q+8nbTov4+1p" crossorigin="anonymous"></script>

    <script>
    document.addEventListener('DOMContentLoaded', function () {
        // Get all FAQ question buttons
        var faqQuestionButtons = document.querySelectorAll('.faq-question');

        // Add click event listener to each FAQ question button
        faqQuestionButtons.forEach(function (button) {
            button.addEventListener('click', function () {
                // Toggle the 'collapsed' class on the clicked question button
                this.classList.toggle('collapsed');
            });
        });
    });
</script>

</body>

</html>
