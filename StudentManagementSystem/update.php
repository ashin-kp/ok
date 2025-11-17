<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Update/Delete Student</title>
</head>
<body>
    <h2>Update/Delete</h2>
    <form method="POST">
        <?php
        include 'connection.php';
        // isset($_POST['rollno']) && !empty($_POST['rollno'])
        // STEP 1: Check if rollno is set
        if (TRUE) {
            $rollno = $_POST['rollno'];
            // STEP 2: Fetch student data
            $sq = "SELECT * FROM stud WHERE rollno = $rollno";
            $res = mysqli_query($con, $sq);

            if ($res && mysqli_num_rows($res) > 0) {
                $row = mysqli_fetch_assoc($res);
                echo "<p>Name: <strong>{$row['name']}</strong></p>";
                echo "Address: <textarea name='add'>{$row['address']}</textarea><br><br>";
                echo "Phone No: <input type='number' name='ph' value='{$row['phone']}' /><br><br>";
                echo "<input type='hidden' name='rollno' value='$rollno' />";
                echo "<input type='submit' name='submit' value='Update' />";
                echo "<input type='submit' name='delete' value='Delete' />";
            } else {
                echo "<p style='color:red;'>No record found for Roll No: $rollno</p>";
            }
        } else {
            // STEP 3: Show input field to enter rollno first
            echo "
            <label>Enter Roll No:</label>
            <input type='number' name='rollno' required />
            <input type='submit' value='Fetch Details' />
            ";
        }

        // STEP 4: Update data
        if (isset($_POST['submit'])) {
            $rollno = $_POST['rollno'];
            $address = $_POST['add'];
            $phone = $_POST['ph'];

            $sq = "UPDATE stud SET phone = '$phone', address = '$address' WHERE rollno = $rollno";
            $res = mysqli_query($con, $sq);

            if ($res) {
                echo "<script>
                alert('Successfully updated');
                window.location.href = 'studentUpdate.php';
                </script>";
            } else {
                echo "<p style='color:red;'>Update failed!</p>";
            }
        }

        // STEP 5: Delete data
        if (isset($_POST['delete'])) {
            $rollno = $_POST['rollno'];
            $sq = "DELETE FROM stud WHERE rollno = $rollno";
            $res = mysqli_query($con, $sq);

            if ($res) {
                echo "<script>alert('Record deleted successfully');</script>";
                header("Location: studentUpdate.php");
            } else {
                echo "<p style='color:red;'>Delete failed!</p>";
            }
        }
        ?>
    </form>
</body>
</html>
