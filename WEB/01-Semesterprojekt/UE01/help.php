<!DOCTYPE html>
<html lang="en">

<?php include 'htmlhead.php'; ?>

<head>
<style>

    .icon-container {
        text-align: center;
        margin-top: 20px;
    }

    .faq-section {
        margin-top: 20px;
    }

    .faq-item {
        margin-bottom: 20px;
        position: relative;
    }

    .faq-question-box {
        background-color: rgba(255, 255, 255, 0.5);
        padding: 15px;
        cursor: pointer;
        transition: background-color 0.3s ease;
        border-radius: 12px;
        box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
        max-width: 500px; /* Set the maximum width */
        margin: 0 auto; /* Center the box horizontally */
        position: relative;
    }

    .faq-question-box::before {
        content: '';
        position: absolute;
        top: 50%;
        right: 15px;
        transform: translateY(-50%) rotate(-45deg);
        border: solid #333;
        border-width: 0 2px 2px 0;
        display: inline-block;
        padding: 3px;
        transition: transform 0.3s ease;
    }

    .faq-question-box.collapsed::before {
        transform: translateY(-50%) rotate(45deg);
    }

    .faq-question {
        margin: 0;
        color: #333;
        font-size: 18px;
    }

    .faq-answer-box {
        padding: 15px;
        background-color: rgba(255, 255, 255, 0.6);
        border-radius: 12px;
        box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
        max-width: 500px; /* Set the maximum width */
        margin: 0 auto; /* Center the box horizontally */
    }

    .faq-answer {
        margin: 0;
        color: #333;
        line-height: 1.6;
    }

    .accordion-item {
        border: 1px solid #ddd;
        border-radius: 12px;
        overflow: hidden;
        transition: background-color 0.2s ease;
    }

    .accordion-item:hover,
    .accordion-item:focus {
        background-color: #e0e0e0;
    }
</style>

</head>

<body>
    <header>
        <a href="index.php"><img src="img/logo-transparent.png" alt="Logo" width="330px"></a>
        <div class="icon-container">
            <h1>Hilfe / FAQs</h1>
            <hr>
            <br>
            <section class="faq-section">
                <div class="accordion" id="faqAccordion">
                    <div class="faq-item">
                        <div class="faq-question-box accordion-item">
                            <h2 class="faq-question" data-bs-toggle="collapse" data-bs-target="#faq1">
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
                        <div class="faq-question-box accordion-item">
                            <h2 class="faq-question" data-bs-toggle="collapse" data-bs-target="#faq2">
                                Gibt es Parkmöglichkeiten am Hotel?
                            </h2>
                        </div>
                        <div id="faq2" class="collapse faq-answer-box">
                            <div class="faq-answer">
                                <p>Ja, unser Hotel verfügt über Parkplätze für Gäste welche beim Buchen dazubestellt werden können.</p>
                            </div>
                        </div>
                    </div>
                    <div class="faq-item">
                        <div class="faq-question-box accordion-item">
                            <h2 class="faq-question" data-bs-toggle="collapse" data-bs-target="#faq3">
                                Wie kann ich mein Passwort ändern?
                            </h2>
                        </div>
                        <div id="faq3" class="collapse faq-answer-box">
                            <div class="faq-answer">
                                <p>Sie können ihr Passwort sowie andere Kontodaten in Ihrem Profil ändern</p>
                            </div>
                        </div>
                    </div>
                </div>
            </section>
        </div>
    </header>
    <footer>
        <p>&copy; <?php echo date("Y"); ?> Hotel Webseite</p>
    </footer>
    <script src="https://code.jquery.com/jquery-3.7.1.js" integrity="sha256-eKhayi8LEQwp4NKxN+CfCh+3qOVUtJn3QNZ0TciWLP4=" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ka7Sk0Gln4gmtz2MlQnikT1wXgYsOg+OMhuP+IlRH9sENBO0LRn5q+8nbTov4+1p" crossorigin="anonymous"></script>

    <script>
        document.addEventListener('DOMContentLoaded', function () {
            // Get all FAQ question boxes
            var faqQuestionBoxes = document.querySelectorAll('.faq-question-box');

            // Add click event listener to each FAQ question box
            faqQuestionBoxes.forEach(function (box) {
                box.addEventListener('click', function () {
                    // Toggle the 'collapsed' class on the clicked question box
                    this.classList.toggle('collapsed');
                });
            });
        });
    </script>
</body>

</html>
