<?php
class Person {
    public $id;
    public $firstname;
    public $lastname;
    public $email;
    public $phone;
    public $department;
    public $funfact;

    function __construct($id, $fn, $ln, $mail, $phone, $dept, $fun) {
        $this->id = $id;
        $this->firstname = $fn;
        $this->lastname=$ln;
        $this->email=$mail;
        $this->phone=$phone;
        $this->department=$dept;
        $this->funfact=$fun;

      }
}
