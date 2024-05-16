import { Component } from '@angular/core';
import { FormControl, Validators } from '@angular/forms';

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.css']
})
export class LoginComponent {
  emailLogIn = new FormControl('', [Validators.required, Validators.email]);
  passwordLogIn = new FormControl('', [Validators.required]);
  hide = true;

  getErrorMessage() {
    if (this.emailLogIn.hasError('required') || this.passwordLogIn.hasError('required')) {
      return 'You have to enter an Email and a Password.';
    }
    return this.emailLogIn.hasError('email') ? 'Not a valid email' : '';
  }

  login() {
    if (this.emailLogIn.value === 'test@test.at' && this.passwordLogIn.value === '12345678') {
      console.log('Login successful.');
    } else {
      console.log('Login failed.');
    }
  }
}
