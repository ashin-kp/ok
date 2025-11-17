<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <h2>View Progress Card</h2>
    <a href ="top.php">View Top Student</a>
    <form method="POST">
        <label>Rollno:</label>
        <select name="rollno">
            <?php
            // session_start();
            include 'connection.php';
            $sq="SELECT * FROM stud ";
            $res=mysqli_query($con,$sq);
            if(mysqli_num_rows($res)>0)
            {
                while($row=mysqli_fetch_assoc($res)){
                    echo "<option value=".$row['rollno'].">".$row['rollno']."</option>";
                }
            }
            ?>
            </select>
            <input type="submit" value="search" name='search'>
            <?php
            if(isset($_POST['search']))
            {
            // $_SESSION['rollno'] = $_POST['rollno'];
            // $rollno = $_SESSION['rollno'];
            $rollno = $_POST['rollno'];
            $sq="SELECT stud.rollno,stud.name,mark.science,mark.maths,mark.english FROM stud LEFT JOIN  mark ON  stud.rollno=mark.rollno WHERE stud.rollno = $rollno";
            $res=mysqli_query($con,$sq);
            if(mysqli_num_rows($res)>0){
                $row=mysqli_fetch_assoc($res);
                echo "Rollno:<u>{$row['rollno']}</u>";
                echo "name:<u>{$row['name']}</u>";
                echo "science:<u>{$row['science']}</u>";
                echo "maths:<u>{$row['maths']}</u>";
                echo "english:<u>{$row['english']}</u>";
                $total = $row['science']+$row['maths']+$row['english'];
                echo "total:<u>{$total}</u>";
            }
        }
            ?>
</form>

</body>
</html>