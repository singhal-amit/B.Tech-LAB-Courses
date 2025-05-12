document.addEventListener( "DOMContentLoaded", function ()
{
  loadXML();
} );

async function loadXML ()
{
  try
  {
    let response = await fetch( "students.xml" );
    if ( !response.ok ) throw new Error( "Failed to fetch student data." );

    let xmlText = await response.text();
    let parser = new DOMParser();
    let xmlDoc = parser.parseFromString( xmlText, "text/xml" );
    displayData( xmlDoc );
  } catch ( error )
  {
    console.error( "Error loading XML:", error );
  }
}

function displayData ( xml )
{
  let table = document.getElementById( "studentTable" );
  let students = xml.getElementsByTagName( "Student" );

  Array.from( students ).forEach( student =>
  {
    let row = document.createElement( "tr" );

    [ "EnrolmentNumber", "Name", "MobileNumber", "EmailId" ].forEach( tag =>
    {
      let cell = document.createElement( "td" );
      cell.textContent = student.getElementsByTagName( tag )[ 0 ].textContent;
      row.appendChild( cell );
    } );

    table.appendChild( row );
  } );
}
