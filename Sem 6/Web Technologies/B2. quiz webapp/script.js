// Quiz questions data structure
const questions = [
  {
    q: "Which tag is used to create a hyperlink in HTML?",
    options: { "1": "&lt;a&gt;", "2": "&lt;link&gt;", "3": "&lt;href&gt;", "4": "&lt;hyperlink&gt;" },
    correct: "1"
  },
  {
    q: "Which CSS property is used to change the background color of an element?",
    options: { "1": "background-color", "2": "color", "3": "bgcolor", "4": "background" },
    correct: "1"
  },
  {
    q: "What does the 'id' attribute in HTML do?",
    options: { "1": "Defines the style of an element", "2": "Identifies a unique element", "3": "Links the element to a CSS class", "4": "Creates a new HTML element" },
    correct: "2"
  },
  {
    q: "How do you add a comment in JavaScript?",
    options: { "1": "/* comment */", "2": "// comment", "3": "&lt;!-- comment --&gt;", "4": "# comment" },
    correct: "2"
  },
  {
    q: "Which HTML element is used to define a paragraph?",
    options: { "1": "&lt;p&gt;", "2": "&lt;h1&gt;", "3": "&lt;div&gt;", "4": "&lt;span&gt;" },
    correct: "1"
  }
];

// Build the quiz HTML dynamically
const quizContainer = document.getElementById( "quizContainer" );
questions.forEach( ( question, index ) =>
{
  const questionDiv = document.createElement( "div" );
  questionDiv.className = "question";
  questionDiv.innerHTML = `
  <h5>Q${ index + 1 }. ${ question.q }</h5>
  <div>
    ${ Object.entries( question.options ).map( ( [ key, value ] ) => `
            <label class="option">
              <input type="radio" name="q${ index + 1 }" value="${ key }"> ${ value }
            </label>
          `).join( '' ) }
  </div>
  `;
  quizContainer.appendChild( questionDiv );
} );

// Listen for quiz submit event
document.getElementById( "quizForm" ).addEventListener( "submit", function ( e )
{
  e.preventDefault();
  let correctCount = 0, incorrectCount = 0, nonSubmittedCount = 0;
  const detailedResults = [];

  // Evaluate each question
  questions.forEach( ( question, index ) =>
  {
    const qNumber = index + 1;
    const selected = document.querySelector( `input[name="q${ qNumber }"]:checked` );
    let status = "";
    if ( !selected )
    {
      nonSubmittedCount++;
      status = "No submitted answer";
    } else if ( selected.value === question.correct )
    {
      correctCount++;
      status = "Your answer is correct";
    } else
    {
      incorrectCount++;
      status = "Your answer is incorrect";
    }
    detailedResults.push( {
      q: question.q,
      options: question.options,
      correct: question.correct,
      userAnswer: selected ? selected.value : null,
      status: status
    } );
  } );

  const results = {
    correctCount,
    incorrectCount,
    nonSubmittedCount,
    detailedResults
  };

  // Store the results in localStorage to be picked up on results page
  localStorage.setItem( "quizResults", JSON.stringify( results ) );
  // Redirect to results page
  window.location.href = "result.html";
} );
