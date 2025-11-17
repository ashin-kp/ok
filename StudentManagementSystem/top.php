<?php
echo "Top Student";
include 'connection.php';
$sq='SELECT stud.rollno,stud.name, mark.science , mark.maths ,mark.english,mark.total FROM stud LEFT JOIN  mark ON
stud.rollno=mark.rollno WHERE mark.total = (SELECT MAX(total) from mark)';
$res = mysqli_query($con , $sq);
$row = mysqli_fetch_assoc($res);
echo "name:".$row['name']."<br>";
echo "rollno:".$row['rollno']."<br>";
echo "science:".$row['science']."<br>";
echo "maths:".$row['maths']."<br>";
echo "english:".$row['english']."<br>";
echo "total:".$row['total']."<br>";
?>