let display = document.querySelector(".display");
let currentValue = "";

function appendToDisplay(value) {
  currentValue += value;
  display.value = currentValue;
}

function clearDisplay() {
  currentValue = "";
  display.value = "";
}

function calculate() {
  try {
    currentValue = eval(currentValue);
    display.value = currentValue;
  } catch (error) {
    display.value = "Error";
  }
}
