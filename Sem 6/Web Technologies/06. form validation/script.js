document.getElementById( "personalForm" ).addEventListener( "submit", function ( event )
{
  event.preventDefault(); // Prevent default form submission

  let isValid = true;
  const form = event.target;

  // Loop through inputs and validate them
  form.querySelectorAll( "input" ).forEach( input =>
  {
    if ( !input.checkValidity() )
    {
      input.classList.add( "is-invalid" );
      isValid = false;
    } else
    {
      input.classList.remove( "is-invalid" );
      input.classList.add( "is-valid" );
    }
  } );

  if ( !isValid ) return;

  // Get values from form fields
  const name = document.getElementById( "name" ).value;
  const email = document.getElementById( "email" ).value;
  const mobile = document.getElementById( "mobile" ).value;
  const gender = document.querySelector( 'input[name="gender"]:checked' )?.value;
  const color = document.getElementById( "color" ).value;

  // Display the result in the textarea
  document.getElementById( "result" ).value = `
Name: ${ name }
Email: ${ email }
Mobile No: ${ mobile }
Gender: ${ gender }
Favourite Colour: ${ color }
    `.trim();
} );
