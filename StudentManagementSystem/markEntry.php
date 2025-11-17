<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form method="POST">
        <label>Rollno:</label>
        <select name = "rollno">
            <option>Enter a no:</option>
    <?php 
    session_start();
    include 'connection.php';
    $sq="SELECT rollno FROM stud";
    $res=mysqli_query($con,$sq);
    if(mysqli_num_rows($res)>0)
    {
        while($row=mysqli_fetch_assoc($res))
        {   
            echo "<option value=".$row["rollno"].">".$row["rollno"]."</option>";
        }
    }
    ?>
    </select>
    <button type="submit" name="search">Search</button>
    <?php

if(isset($_POST['search']))
    {
        $_SESSION['rollno'] = $_POST['rollno'];
        $rollno = $_SESSION['rollno'];
        $sq = "SELECT * FROM stud WHERE rollno=$rollno";
        $res = mysqli_query($con ,$sq);
        if(mysqli_num_rows($res)>0){
            while($row = mysqli_fetch_assoc($res))
            {
                echo "<br>name:<u>".$row['name']."</u>";
            }
        }
    }

    ?>
    <br>
    <label for="">science:</label>
    <input type="number" name="science" id=""><br>
    <label for="">maths:</label>
    <input type="number" name="maths" id=""><br>
    <label for="">english:</label>
    <input type="number" name="english" id=""><br>
    <input type="submit" name="save" value="save">
    <input type="reset"  value="reset">
    <?php
    if(isset($_POST['save']))
    {
    $rollno = $_SESSION['rollno'];
    $science = $_POST['science'];
    $maths = $_POST['maths'];
    $english = $_POST['english'];
    $total = $_POST['science'] + $_POST['maths'] + $_POST['english'];
    $sq = "INSERT INTO mark values($rollno,$science,$maths,$english,$total)";
    $res = mysqli_query($con , $sq);
    if($res)
        echo "<script>alert('insertion success');</script>";
    }
    ?>
    </form>
 
</body>
</html>