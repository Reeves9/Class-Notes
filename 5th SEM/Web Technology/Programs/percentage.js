//fuction to calculate the percentage of 5 subjects
const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});
function percent(subject) {
  var obtained = 0;
  subject.forEach((item) => {
    obtained = obtained + Number(item);
  });
  per = obtained / 5;
  return per;
}
rl.question("enter marks for 5 subjects? ", (subject) => {
  console.log(percent(subject.split(" ")) + "%");
  rl.close();
});
