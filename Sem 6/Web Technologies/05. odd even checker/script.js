document.addEventListener( "DOMContentLoaded", function ()
{
  const checkBtn = document.getElementById( "checkBtn" );
  checkBtn.addEventListener( "click", checkOddOrEven );
} );

function checkOddOrEven ()
{
  let numberInput = document.getElementById( "numberInput" );
  let resultText = document.getElementById( "result" );
  let number = parseInt( numberInput.value );

  if ( isNaN( number ) )
  {
    resultText.textContent = "Please enter a valid number.";
    resultText.className = "error";
  } else
  {
    if ( number % 2 === 0 )
    {
      resultText.textContent = `The number ${ number } is EVEN.`;
      resultText.className = "success";
    } else
    {
      resultText.textContent = `The number ${ number } is ODD.`;
      resultText.className = "success";
    }
  }

  // Clear input after checking
  numberInput.value = "";
}
