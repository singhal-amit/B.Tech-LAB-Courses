let expression = "";

function AddNumber ( value )
{
  expression += value;
  UpdateDisplay();
}

function ClearText ()
{
  expression = "";
  UpdateDisplay();
}

function ClearLastCharacter ()
{
  expression = expression.slice( 0, -1 );
  UpdateDisplay();
}

function SquareValue ()
{
  try
  {
    const squared = Math.pow( eval( expression ), 2 );
    expression = squared.toString();
    UpdateDisplay();
  } catch
  {
    expression = "";
    UpdateDisplay( "Error" );
  }
}

function Evaluate ()
{
  try
  {
    const result = eval( expression );
    UpdateDisplay( result );
    expression = result.toString(); // to continue calculations
  } catch
  {
    UpdateDisplay( "Error" );
    expression = "";
  }
}

function UpdateDisplay ( result = "" )
{
  const resultSpan = document.getElementById( "Result-Part" );
  const exprSpan = document.getElementById( "Expr-Part" );

  resultSpan.textContent = result !== "" ? result : "";
  exprSpan.textContent = expression;
}
