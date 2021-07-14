
<?php
$to      = 'sato_alexandre@hotmail.com';
$subject = 'the subject';
$message = 'hello';
$headers = array(
    'From' => 'webmaster@example.com',
    'Reply-To' => 'webmaster@example.com',
    'X-Mailer' => 'PHP/' . phpversion()
);

$status = mail($to, $subject, $message, $headers);

if($status)
{
	print ("<p>Your message has been sent,  /*" .$fromAddr. "*/ !</p>");
}
else
{
	print ("<p>An error occurred while trying to send the mail.</p>");
}

?>

