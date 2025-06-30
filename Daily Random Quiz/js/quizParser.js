// A function that processes the quiz data from the JSON file
function processQuizData(jsonString, quizTopicIndex) {
	// Parse the JSON string into an object
	const quizData = JSON.parse(jsonString);
	// Store title and description in string variables
	const quizTitle = quizData.quizzes[quizTopicIndex].title;
	const quizDescription = quizData.quizzes[quizTopicIndex].description;
	// Store quiz questions in a Map object
	const quizMap = new Map();
	quizData.quizzes[quizTopicIndex].quiz.forEach((item, index) => {
		if (item.type == "free_text") quizMap.set(index + 1, {
			question: item.question,
			answer: item.answer,
			type: item.type,
			difficulty: item.difficulty
		});
		else quizMap.set(index + 1, {
			question: item.question,
			answer: item.answer,
			type: item.type,
			options: item.options,
			difficulty: item.difficulty
		});
	});
	return {
		title: quizTitle,
		description: quizDescription,
		quiz: quizMap
	};
}
// A function that assigns each question difficulty to points
function getQuizPassScore(quiz) {
	if (quiz.difficulty == "easy") score = 5;
	else if (quiz.difficulty == "medium") score = 10;
	else score = 20;
	return score;
}
// Random number generator based off of date, resulting in any number between 0 and 9
function getRandomNumberFromDate() {
	const now = new Date();
	const seed = now.getFullYear() * 10000 + (now.getMonth() + 1) * 100 + now.getDate();
	const random = Math.sin(seed) * 10000;
	const result = Math.floor((random - Math.floor(random)) * 10);
	return result;
}
// Function to ensure that the user is warned before exiting the questions screen that the progress won't be saved
window.onbeforeunload = function() {
	if (document.getElementById("questionScreen").style.display === 'block' || document.getElementById("submitAnswerScreen").style.display === 'block') {
		return "Any progress you made will not be saved";
	} else {
		//Reload or exit happens without prompt
	}
}
// function to display the rules
function viewRules() {
	document.getElementById("rulesScreen").style.display = 'block';
	document.getElementById("topicIntroScreen").style.display = 'none';
	document.getElementById("questionScreen").style.display = 'none';
	document.getElementById("resultsScreen").style.display = 'none';
	document.getElementById("submitAnswerScreen").style.display = 'none';
	const getTopicButton = document.getElementById('rulesScreenButton');
	getTopicButton.addEventListener('click', getTodayTopicPageInitialization);
}
// Initializes today's topic page with the information
function getTodayTopicPageInitialization() {
	document.getElementById("rulesScreen").style.display = 'none'; // Hide rules screen 
	document.getElementById("topicIntroScreen").style.display = 'block'; // Shows topic screen
	let now = new Date();
	document.getElementById("dateToday").innerHTML = "Date: " + (now.toDateString());
	document.getElementById("topicScreenTopicName").innerHTML = "Quiz Topic Today: " + todaysQuiz.title; // Today's Quiz (Initializes in Topic Info Page)
	document.getElementById("questionScreenTopicName").innerHTML = "Topic: " + todaysQuiz.title; // Today's Quiz (Initializes in Question Page)
	console.log(todaysQuiz.title);
	document.getElementById("topicScreenDescription").innerHTML = "Description: " + todaysQuiz.description; // Current Description
	console.log(todaysQuiz.description);
	const questionCount = 10; // 10 questions in each quiz
	document.getElementById("topicScreenNumberOfQuestions").innerHTML = "Total Number of Questions: " + questionCount;
	console.log(questionCount);
	let totalPointsPossible = 0;
	for (i = 1; i <= 10; i++) {
		totalPointsPossible += getQuizPassScore(qMap.get(i)); // adds total points possible per question
	}
	document.getElementById("topicScreenPointsPossible").innerHTML = "Total Number of Points Possible: " + totalPointsPossible;
	console.log(totalPointsPossible);
	console.log(todaysQuiz.quiz);
	const viewRulesAgain = document.getElementById('backToRules');
	viewRulesAgain.addEventListener('click', viewRules);
	const startQuestionsButton = document.getElementById('topicIntroScreenButton');
	startQuestionsButton.addEventListener('click', questionScreen);
}
// Function responsible for going to question screen
function questionScreen() {
	document.getElementById("topicIntroScreen").style.display = 'none'; // Hide topic screen
	document.getElementById("questionScreen").style.display = 'block'; // Shows question screen
	fetchQuestion(); // Gets the first questions
	activeTimer = true;
	countdown(); // Starts the countdown for the questions
}
// Function that is responsible for maintaining the control bar information
function controlBar() {
	document.getElementById("yourScore").innerHTML = "Your Score: " + userScore;
	document.getElementById("yourTimeLeft").innerHTML = "Time Remaining: ";
}
// Function responsible for handling user input
function handleFRQInput() {
	const frqInput = document.getElementById("frqAnswer");
	if (frqInput.value.trim() !== "") {
		submitAnswerButton.style.display = 'inline-block';
	} else {
		submitAnswerButton.style.display = 'none';
	}
}
// The function that is responsible for fetching the next question
function fetchQuestion() {
	if (remaining <= 0) { // Case where all the questions are done
		document.getElementById("question").innerHTML = "";
		endScreenDisplay(); // Since all the questions are over, the end screen display is called
		remaining--; // triggers the end of the countdown function
		return;
	}
	currentQuestionNumber = Math.floor(Math.random() * 10) + 1; // Random number generator between 1 and 10
	if (!chosenQuestions.includes(currentQuestionNumber)) {
	awaitingNextQuestion = false;
	document.getElementById("dot" + remaining).style.backgroundColor = "yellow";
	document.getElementById("dot" + remaining).innerHTML = getQuizPassScore(qMap.get(currentQuestionNumber));    
	document.getElementById("timeUpNotification").style.display = 'none'; // Hides the time up notification
	document.getElementById("submitAnswerScreen").style.display = 'none'; // Hides the question result screen
	document.getElementById("questionScreen").style.display = 'block'; // Shows the question screen
    document.getElementById("questionScreenQuestionSection").style.display = 'block';
    document.getElementById("questionScreenControlSection").style.display = 'block';		
    controlBar();
		console.log(currentQuestionNumber); // Testing purposes to see which question was chosen
		document.getElementById("question").innerHTML = qMap.get(currentQuestionNumber).question + " "; // Current Question
		console.log("Question: " + qMap.get(currentQuestionNumber).question);
		console.log("Pass Score: " + getQuizPassScore(qMap.get(currentQuestionNumber)));
		timeRemaining = 60; // Resets the timer for each question
		if (qMap.get(currentQuestionNumber).type == "multiple_choice") { // Case if Multiple Choice
			const frq = document.getElementById("questionScreenFRQAnswerType");
			frq.style.display = 'none'; // Makes FRQ box hidden when multiple choice
			const mcq = document.getElementById("questionScreenMCQAnswerType");
			mcq.style.display = 'block'; // Makes MCQ box visible when multiple choice
			submitAnswerButton.style.display = 'none'; // Hides the submit button to ensure user doesn't accidentally hit submit when they haven't answered
			const labelA = document.querySelector("label[for='optionA']");
			labelA.textContent = "A. " + qMap.get(currentQuestionNumber).options[0] + " ";
			const labelB = document.querySelector("label[for='optionB']");
			labelB.textContent = "B. " + qMap.get(currentQuestionNumber).options[1] + " ";
			const labelC = document.querySelector("label[for='optionC']");
			labelC.textContent = "C. " + qMap.get(currentQuestionNumber).options[2] + " ";
			const labelD = document.querySelector("label[for='optionD']");
			labelD.textContent = "D. " + qMap.get(currentQuestionNumber).options[3] + " ";
			console.log("Options: " + qMap.get(currentQuestionNumber).options);
			document.getElementsByName("mcq").forEach(radio => {
				radio.addEventListener("change", () => {
					submitAnswerButton.style.display = 'inline-block';
				});
			});
		} else if (qMap.get(currentQuestionNumber).type == "free_text") { // Case if Free-Response
			const mcq = document.getElementById("questionScreenMCQAnswerType");
			mcq.style.display = 'none'; // Makes MCQ box hidden when free response
			const frq = document.getElementById("questionScreenFRQAnswerType");
			frq.style.display = 'block'; // Makes FRQ box visible when free response
			submitAnswerButton.style.display = 'none'; // Hides the submit button to ensure user doesn't accidentally hit submit when they haven't answered
			const frqInput = document.getElementById("frqAnswer");
			frqInput.value = "";
			frqInput.removeEventListener("input", handleFRQInput); // Removes old event listener
			frqInput.addEventListener("input", handleFRQInput); // Adds new event listener
		}
		console.log("Correct Answer: " + qMap.get(currentQuestionNumber).answer);
		console.log("___________________________________________________________________");
		chosenQuestions.push(currentQuestionNumber); // pushes the random number chosen into the array to indicate it was already chosen
		remaining--; // decrements the remaining number of questions
		// Event Listeners For Each of the Buttons/Actions
		const skipQuestionButton = document.getElementById('skipQuestionButton');
		skipQuestionButton.addEventListener('click', skipQuestion);
		const quitQuizButton = document.getElementById('quitQuizButton');
		quitQuizButton.addEventListener('click', quitQuiz);
	} else {
		fetchQuestion(); // calls the function again incase the random number generator already chose the number
	}
}
// This function is responsible for counting down the timer
function countdown() {
	if(!activeTimer){return;}
	if (timeRemaining >= 0 && remaining != -1) {
		countdownElement.textContent = "Time Remaining: " + timeRemaining + " Seconds";
		timeRemaining--;
		setTimeout(countdown, 1000);
	} else if (timeRemaining < 0 && remaining != -1 && !awaitingNextQuestion) {
		document.getElementById("questionScreenQuestionSection").style.display = 'none';
		document.getElementById("questionScreenControlSection").style.display = 'none';
		document.getElementById("timeUpNotification").style.display = 'block';
		setTimeout(submitAnswer, 2000);
    	restartCountdown();
	} else if((timeRemaining < 0 && remaining != -1 && awaitingNextQuestion)){
    	restartCountdown();		
	}
}

// This function waits to restart the countdown timer
function restartCountdown() {
  if(timeRemaining < 0){
    setTimeout(restartCountdown, 10);
  } else{
	setTimeout(countdown, 10);    
  }
}

// This function is responsible for displaying the submit answer screen
function submitAnswerResult(resultOfAnswer) {
	awaitingNextQuestion = true;
	document.getElementById("questionScreen").style.display = 'none';
	document.getElementById("timeUpNotification").style.display = 'none';
	document.getElementById("submitAnswerScreen").style.display = 'block';
	if (resultOfAnswer === "correct") {
		submitAnswerScreen.style.backgroundColor = "#254D26"; // Dark Pastel Green
		document.getElementById("resultingAnswer").innerHTML = "Correct!";
		document.getElementById("plusPoints").innerHTML = "+ " + getQuizPassScore(qMap.get(currentQuestionNumber)) + " Points";
	} else if (resultOfAnswer === "incorrect") {
		submitAnswerScreen.style.backgroundColor = "#550000"; // Dark Pastel Red
		document.getElementById("resultingAnswer").innerHTML = "Incorrect!";
		document.getElementById("plusPoints").innerHTML = "Correct Answer: " + qMap.get(currentQuestionNumber).answer;
	} else {
		submitAnswerScreen.style.backgroundColor = "#5B5B57";
		document.getElementById("resultingAnswer").innerHTML = "Question Skipped";
		document.getElementById("plusPoints").innerHTML = "Correct Answer: " + qMap.get(currentQuestionNumber).answer;
	}
	const nextQuestion = document.getElementById('nextQuestion'); // Event listener for the next question button
	nextQuestion.addEventListener('click', fetchQuestion); // Calls the function to fetch next question
	const quitNow = document.getElementById('goToEnd'); // Event listener for the quit quiz button
	quitNow.addEventListener('click', adjustSkipCounter); // Calls the function to quit the quiz
}
// function to adjust skip counter before sending it to end screen
function adjustSkipCounter() {
	skipped -= 1;
	quitQuiz();
}
// Function dealing with unchecking radio buttons to ensure that it isn't automatically selected for future questions
function uncheckRadioButton() {
	if (qMap.get(currentQuestionNumber).type === "multiple_choice") {
		const radios = document.getElementsByName("mcq"); // Get all radio buttons with name "mcq"
		let selectedOption = null;
		for (let i = 0; i < radios.length; i++) {
			if (radios[i].checked) {
				selectedOption = i; // Save the index of the selected option
				radios[selectedOption].checked = false; // Unchecks the selected option for future questions
				break;
			}
		}
	}
}
// Function dealing with skip button being hit in the question section
function skipQuestion() {
	let dotNumber = remaining + 1;
	document.getElementById("dot" + dotNumber).style.backgroundColor = "white";
	uncheckRadioButton();
	skipped += 1;
	submitAnswerResult("skipped");
}
// Function dealing with submit button being hit in the question section
function submitAnswer() {
	let dotNumber = remaining + 1; // This keeps track of the dot styling
	if (qMap.get(currentQuestionNumber).type === "multiple_choice") {
		const radios = document.getElementsByName("mcq"); // Get all radio buttons with name "mcq"
		let selectedOption = null;
		for (let i = 0; i < radios.length; i++) {
			if (radios[i].checked) {
				selectedOption = i; // Save the index of the selected option
				radios[i].checked = false; // Unchecks the selected option for future questions
				break;
			}
		}
		const selectedAnswer = qMap.get(currentQuestionNumber).options[selectedOption];
		const correctAnswer = qMap.get(currentQuestionNumber).answer;
		if (selectedOption === null) {
			skipQuestion();
		} else if (selectedAnswer === correctAnswer) {
			userScore += getQuizPassScore(qMap.get(currentQuestionNumber));
			correct += 1;
			document.getElementById("dot" + dotNumber).style.backgroundColor = "#77DD77";
			submitAnswerResult("correct");
		} else {
			incorrect += 1;
			document.getElementById("dot" + dotNumber).style.backgroundColor = "#FF6961";
			submitAnswerResult("incorrect");
		}
	} else if (qMap.get(currentQuestionNumber).type === "free_text") {
		const frqInput = document.getElementById("frqAnswer");
		const userAnswer = frqInput.value.trim(); // Removes whitespace
		frqInput.value = ""; // Clear the input for the next question
		if (userAnswer === "") {
			skipQuestion();
		} else if (userAnswer.toLowerCase() === qMap.get(currentQuestionNumber).answer.toLowerCase()) {
			userScore += getQuizPassScore(qMap.get(currentQuestionNumber));
			correct += 1;
			document.getElementById("dot" + dotNumber).style.backgroundColor = "#77DD77";
			submitAnswerResult("correct");
		} else {
			incorrect += 1;
			document.getElementById("dot" + dotNumber).style.backgroundColor = "#FF6961";
			submitAnswerResult("incorrect");
		}
	}
}
// Function that deals with quit button being hit in the question section
function quitQuiz() {
	uncheckRadioButton();
	skipped += (remaining + 1); // Updates the skipped question count for the results page
	remaining = 0;
	fetchQuestion();
}
// Function responsible for displaying the last screen
function endScreenDisplay() {
	document.getElementById("questionScreen").style.display = 'none'; // Hide question screen
	document.getElementById("submitAnswerScreen").style.display = 'none'; // Hides the question result screen
	document.getElementById("resultsScreen").style.display = 'block'; // Shows results screen
	document.getElementById("resultsScreenFinalScore").innerHTML = "Your Final Score: " + userScore;
	document.getElementById("yourCorrectFinal").innerHTML = correct + " Correct";
	document.getElementById("yourIncorrectFinal").innerHTML = incorrect + " Incorrect";
	document.getElementById("yourFinalSkipped").innerHTML = skipped + " Skipped";
	// Event Listeners
	const restartQuizButton = document.getElementById('restartQuizButton');
	restartQuizButton.addEventListener('click', restartQuiz); // Restart button goes back to rules screen
}
// Function that deals with resetting all of the information before the quiz restarts
function restartQuiz() {
	for(let i = 1; i <= 10; i++){ // For Loop Responsible for resetting the progress bar
		document.getElementById("dot" + i).style.backgroundColor = "#bbb";
		document.getElementById("dot" + i).innerHTML = "?";  		
	}
	currentQuestionNumber = null; // Restarts as there is no new number
	chosenQuestions.length = 0; // Resets the tracker for the chosen questions
	userScore = 0;
	correct = 0;
	incorrect = 0;
	remaining = 10;
	skipped = 0;
	timeRemaining = 60;
	activeTimer = false;
	viewRules(); // Restart button goes back to rules screen 
}
// The "main part" of this program below, it contains the function calls to initialize all the information and also variables that must be outside functions
var quizTopicIndex = getRandomNumberFromDate(); //Calls random number generator to get the number that would correspond to today's quiz
const todaysQuiz = processQuizData(jsonString, quizTopicIndex); // Calls the function to get the quiz data corresponding to the data
const qMap = todaysQuiz.quiz; // qMap initialization for today's quiz
viewRules(); // Initializes the program

let activeTimer = false; // Variable that the countdown uses to check if the timer is active, ends it otherwise.
let awaitingNextQuestion  = false; // Variable to keep track of whether or not one is in the screen with results (to prevent the countdown timer from submitting duplicates)

let currentQuestionNumber = null; // Variable to keep track of the current question number (as it is randomly chosen)
let chosenQuestions = []; //Array that keeps track of already selected questions
// variables to keep track of control bar info
let userScore = 0; // Keeps track of the user's total points
let correct = 0;
let incorrect = 0;
let remaining = 10; // Keeps track of how many questions are left
let skipped = 0;
let timeRemaining = 60; // Keeps track of time remaining in seconds
// Event Listeners & Other Elements below
const submitAnswerButton = document.getElementById('submitAnswerButton');
submitAnswerButton.addEventListener('click', submitAnswer);
const countdownElement = document.getElementById('yourTimeLeft'); // Keeps track of countdown