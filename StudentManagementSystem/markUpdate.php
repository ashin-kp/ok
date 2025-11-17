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
        $sq = "SELECT stud.name, mark.science, mark.maths, mark.english FROM stud 
        LEFT JOIN mark ON stud.rollno = mark.rollno 
        WHERE stud.rollno = '$rollno'";
        $res=mysqli_query($con,$sq);
            if(mysqli_num_rows($res)>0){
            while($row = mysqli_fetch_assoc($res))
            {
                echo "<br>name:<input type='text' value={$row['name']}>";
                echo "<br>science:<input type='text' name='science' value={$row['science']}>";
                echo "<br>maths:<input type='text' name='maths' value={$row['maths']}>";
                echo "<br>english:<input type='text' name='english' value={$row['english']}>";

            }
        }
    }
?>
<input type="submit" value="Update" name="update">
<input type="reset" value="reset">
<?php
if(isset($_POST['update']))
{
    $rollno = $_SESSION['rollno'];
    $science = $_POST['science'];
    $maths = $_POST['maths'];
    $english = $_POST['english'];
    $total = $_POST['science'] + $_POST['maths'] + $_POST['english'];
    $sq="UPDATE mark set science=$science,maths=$maths,english=$english,total=$total where rollno=$rollno";
    $res = mysqli_query($con ,$sq);
    if($res){
        echo "<script>alert('updated successfully')</script>";
    }
}
?>
</form>
</body>
</html>