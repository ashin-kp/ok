<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    
    <table border="1">
        <tr>
            <th>Rollno</th>
            <th>name</th>
            <th>Address</th>
            <th>PhoneNo</th>
            <th>Update</th>
        </tr>
        <?php
        include 'connection.php';
        $sq = "SELECT * FROM stud";
        $res = mysqli_query($con ,$sq);
        if(mysqli_num_rows($res)>0){
            while($row = mysqli_fetch_assoc($res)){
                echo "<tr>";
                echo "<td><input type='text' name='rollno' value=".$row['rollno']."></td>";
                echo "<td>".$row['name']."</td>";
                echo "<td>".$row['address']."</td>";
                echo "<td>".$row['phone']."</td>";
                echo "<td><form action='update.php' method='POST'><input type='hidden' name='rollno' value={$row['rollno']}>
                <input type='submit' name='update' value='update'></form></td>";
                echo "</tr>";
            }
        }
        ?>
    </table>
   

</body>
</html>