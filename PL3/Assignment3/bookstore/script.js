// Real data for featured and all books
const featuredBooksData = [
    {
        title: "The Great Gatsby",
        author: "F. Scott Fitzgerald",
        imgSrc: "great-gatsby.jpg"
    },
    {
        title: "To Kill a Mockingbird",
        author: "Harper Lee",
        imgSrc: "to-kill-a-mockingbird.jpg"
    },
    {
        title: "1984",
        author: "George Orwell",
        imgSrc: "1984.jpg"
    },
    // Add more featured books here
];

const allBooksData = [
    {
        title: "The Catcher in the Rye",
        author: "J.D. Salinger",
        imgSrc: "catcher-in-the-rye.jpg"
    },
    {
        title: "Pride and Prejudice",
        author: "Jane Austen",
        imgSrc: "pride-and-prejudice.jpg"
    },
    {
        title: "The Hobbit",
        author: "J.R.R. Tolkien",
        imgSrc: "the-hobbit.jpg"
    },
    // Add more books here
];

// Function to display books
function displayBooks(books, containerId) {
    const container = document.getElementById(containerId);
    container.innerHTML = "";

    books.forEach((book, index) => {
        const bookDiv = document.createElement("div");
        bookDiv.className = "book";
        bookDiv.innerHTML = `
            <img src="${book.imgSrc}" alt="${book.title}">
            <p>${book.title}</p>
            <p>By ${book.author}</p>
            <button class='add-button' onclick="addToCart(${index})">Add to Cart</button>
        `;
        container.appendChild(bookDiv);
    });
}

// Initialize the page with featured and all books
displayBooks(featuredBooksData, "featured-books");
displayBooks(allBooksData, "all-books");

// Shopping cart functionality
let cart = [];
let cartCount = 0;

function addToCart(index) {
    const book = allBooksData[index];
    cart.push(book);
    cartCount++;
    document.getElementById("cart-count").textContent = cartCount;
}

// JavaScript for mobile menu toggle
function toggleMenu() {
    const nav = document.querySelector('nav');
    nav.classList.toggle('show');
}
