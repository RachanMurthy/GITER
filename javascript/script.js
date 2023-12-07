let computer_result = document.querySelector("#computer");
let player_result = document.querySelector("#player");
let result_result = document.querySelector("#result");
let btn_choice = document.querySelectorAll("#choicebtn");
let player_choice;
let computer_choice;

btn_choice.forEach(btn => btn.addEventListener("click", () => {
    player_choice = btn.value;
    player_result.textContent = `PLAYER : ${btn.value}`;
    computer_play();
}))

function computer_play(){
    computer_choice = Math.floor(Math.random() * 3) + 1;

    if (computer_choice == 1){
        computer_choice = "ROCK";
    }
    else if (computer_choice == 2) {
        computer_choice = "PAPER";
    }
    else {
        computer_choice = "SCISSOR";
    }
    computer_result.textContent = `COMPUTER : ${computer_choice}`;

    result_play()
}

function result_play(){
    if (computer_choice == player_choice){
        result_result.textContent = "RESULT : DRAW"
        return 
    }
    if (computer_choice == "ROCK" & player_choice == "SCISSOR"){
        result_result.textContent = "RESULT : WINNER"
    }

    else if (computer_choice == "SCISSOR" & player_choice == "PAPER"){
        result_result.textContent = "RESULT : WINNER"
    }

    else if (computer_choice == "PAPER" & player_choice == "ROCK"){
        result_result.textContent = "RESULT : WINNER"
    }

    else {
        result_result.textContent = "RESULT : LOSER"
    }

    
}