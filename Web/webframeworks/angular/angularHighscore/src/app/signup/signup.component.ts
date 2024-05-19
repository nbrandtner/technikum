import { Component } from '@angular/core';
import { FormControl, Validators } from '@angular/forms';

@Component({
  selector: 'app-signup',
  templateUrl: './signup.component.html',
  styleUrls: ['./signup.component.css']
})
export class SignupComponent {
  email = new FormControl('', [Validators.required, Validators.email]);
  password = new FormControl('', [Validators.required]);
  confirmPassword = new FormControl('', [Validators.required]);
  company = new FormControl({value: 'FH Technikum Wien', disabled: true});
  street = new FormControl('');
  city = new FormControl('');
  zip = new FormControl('', [Validators.pattern('\\d*')]);
  hidePassword = true;
  hideConfirmPassword = true;

  getErrorMessage() {
    if (this.email.hasError('required') || this.password.hasError('required') || this.confirmPassword.hasError('required')) {
      return 'You have to enter an Email and a Password.';
    }
    if(this.password.value !== this.confirmPassword.value){
      return this.password.hasError('Passwords don\'t match.') ? 'Passwords don\'t match.' : '';
    }
    return this.email.hasError('email') ? 'Not a valid email' : '';
  }

  register() {
    if (this.password.value !== this.confirmPassword.value) {
      console.log('Passwords don\'t match.');
    } else if (this.email.invalid) {
      console.log('Invalid email.');
    } else {
      if(this.password.value !== '' && this.confirmPassword.value !== ''){
        console.log('Registrierung erfolgreich.');
      }else{
        console.log('Registrierung fehlgeschlagen.');
      }
    }
  }
}
