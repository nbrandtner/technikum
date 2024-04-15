<?php
include("./models/person.php");
class DataHandler
{
    public function queryPersons()
    {
        $res =  $this->getDemoData();
        return $res;
    }

    public function queryPersonById($id)
    {
        $result = array();
        foreach ($this->queryPersons() as $val) {
            if ($val[0]->id == $id) {
                array_push($result, $val);
            }
        }
        return $result;
    }

    public function queryPersonByName($name)
    {
        $result = array();
        foreach ($this->queryPersons() as $val) {
            if ($val[0]->lastname == $name) {
                array_push($result, $val);
            }
        }
        return $result;
    }

    public function queryPersonByFunfact($funfact)
    {
        $result = array();
        foreach ($this->queryPersons() as $val) {
            if($val[0]->funfact == $funfact)
            {
                array_push($result, $val);
            }
        }
        return $result;
    }

    private static function getDemoData()
    {
        $demodata = [
            [new Person(1, "Jane", "Doe", "jane.doe@fhtw.at", 1234567, "Central IT", "Autistic")],
            [new Person(2, "John", "Doe", "john.doe@fhtw.at", 34345654, "Help Desk", "None")],
            [new Person(3, "baby", "Doe", "baby.doe@fhtw.at", 54545455, "Management", "First Name is Baby???")],
            [new Person(4, "Mike", "Smith", "mike.smith@fhtw.at", 343477778, "Faculty", "Smiths Microphones")],
            [new Person(5,"Luis","Smith","luis.smith@fhtw.at",347478770,"Psych Ward", "Likes DnD too much")]
        ];
        return $demodata;
    }
}
