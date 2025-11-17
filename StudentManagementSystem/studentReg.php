<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <h2>Student registration</h2>
    <form action="" method="POST">
        Rollno: <input type="number" name="rollno" id=""><br>
        Name : <input type="text" name="name" id=""><br>
        Address : <textarea rows="2" cols="4" name="address"></textarea><br>
        PhoneNo: <input type="number" name="phone" id=""><br>
        username: <input type="text" name="username" id=""><br>
        password: <input type="password" name="password" id=""><br>
        re-enter password: <input type="password" name="repassword" id=""><br>
        <button type="submit" name="register">register</button>
    </form>
    <?php 
    if(isset($_POST['register'])){
        $rollno=$_POST['rollno'];
        $name=$_POST['name'];
        $address=$_POST['address'];
        $phoneNo=$_POST['phone'];
        $username=$_POST['username'];
        $password=$_POST['password'];
        $repassword=$_POST['repassword'];
        $con=mysqli_connect("localhost","root","","studentManagement");
        if(!$con)
        {
            echo "connection error";
        }
        $sq="INSERT INTO stud values($rollno,'$name','$address',$phoneNo,'$username','$password')";
        $res=mysqli_query($con,$sq);
        if($res){
            echo "<script>alert('successfully inserted');</script>";
        }
    }
    ?>
</body>
</html>