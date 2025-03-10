document.querySelectorAll('input[name="method"]').forEach((elem) => {
    elem.addEventListener("change", function(event) {
        if (event.target.value === "fermat") {
            document.getElementById("fermat-inputs").style.display = "block";
            document.getElementById("pollard-inputs").style.display = "none";
        } else {
            document.getElementById("fermat-inputs").style.display = "none";
            document.getElementById("pollard-inputs").style.display = "block";
        }
    });
});

function isPerfectSquare(num) {
    let sqrtNum = Math.floor(Math.sqrt(num));
    return (sqrtNum * sqrtNum === num);
}

function fermatFactorization() {
    console.log("Fermat Factorization");
    let n = parseInt(document.getElementById("fermat-number").value);
    if (n <= 0) {
        document.getElementById("result").innerText = "Please enter a positive integer.";
        return;
    }

    let x = Math.ceil(Math.sqrt(n));
    let w, y, a, b;

    while (true) {
        w = x * x - n;
        if (isPerfectSquare(w)) {
            y = Math.sqrt(w);
            a = x + y;
            b = x - y;
            document.getElementById("result").innerText = `Factors of ${n}: ${a} and ${b}`;
            console.log(`Factors of ${n}: ${a} and ${b}`);
            return;
        }
        x++;
    }
}

function gcd(a, b) {
    while (b) {
        let temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

function modExp(base, exp, mod) {
    let result = 1;
    while (exp > 0) {
        if (exp % 2 === 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp = Math.floor(exp / 2);
    }
    return result;
}

function pollardFactorization() {
    console.log("Pollard Factorization");
    let n = parseInt(document.getElementById("pollard-number").value);
    let B = parseInt(document.getElementById("pollard-bound").value);
    if (n <= 0 || B <= 0) {
        document.getElementById("result").innerText = "Please enter positive integers for n and B.";
        return;
    }

    let a = 2;
    let e = 2;

    while (e <= B) {
        a = modExp(a, e, n);
        e++;
    }

    let p = gcd(a - 1, n);

    if (p > 1 && p < n)
        document.getElementById("result").innerText = `A non-trivial factor of ${n} is ${p}`;
    else
        document.getElementById("result").innerText = "Factorization failed. Try a different bound value B.";
}