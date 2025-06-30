const jsonString = `{
  "title": "Quiz Book",
  "description": "This quiz book contains quizzes from multiple topics.",
  "quizzes": [
    {
      "title": "History",
      "description": "This quiz contains ten questions about historical events and figures. Answers include a mix of multiple choice questions and one-worded free text answers.",
      "quiz": [
        {
          "question": "Who was the first President of the United States?",
          "answer": "Washington",
          "type": "free_text",
          "difficulty": "easy"
        },
        {
          "question": "In which year did World War II end?",
          "answer": "1945",
          "type": "free_text",
          "difficulty": "easy"
        },
        {
          "question": "Which ancient civilization built the pyramids?",
          "options": [
            "Mesopotamians",
            "Romans",
            "Egyptians",
            "Greeks"
          ],
          "answer": "Egyptians",
          "type": "multiple_choice",
          "difficulty": "medium"
        },
        {
          "question": "Who was known as the 'Iron Lady'?",
          "options": [
            "Margaret Thatcher",
            "Angela Merkel",
            "Indira Gandhi",
            "Golda Meir"
          ],
          "answer": "Margaret Thatcher",
          "type": "multiple_choice",
          "difficulty": "medium"
        },
        {
          "question": "What was the name of the ship that carried the Pilgrims to America in 1620?",
          "answer": "Mayflower",
          "type": "free_text",
          "difficulty": "easy"
        },
        {
          "question": "Which empire was ruled by Julius Caesar?",
          "answer": "Roman",
          "type": "free_text",
          "difficulty": "medium"
        },
        {
          "question": "Who was the principal author of the Declaration of Independence?",
          "options": [
            "Thomas Jefferson",
            "Benjamin Franklin",
            "John Adams",
            "James Madison"
          ],
          "answer": "Thomas Jefferson",
          "type": "multiple_choice",
          "difficulty": "medium"
        },
        {
          "question": "In which year did the Berlin Wall fall?",
          "answer": "1989",
          "type": "free_text",
          "difficulty": "hard"
        },
        {
          "question": "Who was the first woman to fly solo across the Atlantic Ocean?",
          "options": [
            "Amelia Earhart",
            "Bessie Coleman",
            "Harriet Quimby",
            "Jacqueline Cochran"
          ],
          "answer": "Amelia Earhart",
          "type": "multiple_choice",
          "difficulty": "easy"
        },
        {
          "question": "Which country was the first to land a man on the moon?",
          "answer": "USA",
          "type": "free_text",
          "difficulty": "easy"
        }
      ]
    },
    {
      "title": "Geography",
      "description": "This quiz contains ten questions about geographical locations and features. Answers include a mix of multiple choice questions and free text answers.",
      "quiz": [
        {
          "question": "What is the capital of France?",
          "answer": "Paris",
          "type": "free_text",
          "difficulty": "easy"
        },
        {
          "question": "Which continent is the Sahara Desert located in?",
          "answer": "Africa",
          "type": "free_text",
          "difficulty": "easy"
        },
        {
          "question": "Which country has the largest population?",
          "options": [
            "China",
            "India",
            "United States",
            "Indonesia"
          ],
          "answer": "China",
          "type": "multiple_choice",
          "difficulty": "medium"
        },
        {
          "question": "What is the longest river in the world?",
          "options": [
            "Amazon River",
            "Nile River",
            "Yangtze River",
            "Mississippi River"
          ],
          "answer": "Nile River",
          "type": "multiple_choice",
          "difficulty": "medium"
        },
        {
          "question": "Which country is known as the Land of the Rising Sun?",
          "answer": "Japan",
          "type": "free_text",
          "difficulty": "easy"
        },
        {
          "question": "What is the smallest country in the world?",
          "answer": "Vatican City",
          "type": "free_text",
          "difficulty": "medium"
        },
        {
          "question": "Which ocean is the largest?",
          "options": [
            "Atlantic Ocean",
            "Indian Ocean",
            "Arctic Ocean",
            "Pacific Ocean"
          ],
          "answer": "Pacific Ocean",
          "type": "multiple_choice",
          "difficulty": "easy"
        },
        {
          "question": "What is the capital of Australia?",
          "answer": "Canberra",
          "type": "free_text",
          "difficulty": "medium"
        },
        {
          "question": "Which mountain is the highest in the world?",
          "options": [
            "Mount Everest",
            "K2",
            "Kangchenjunga",
            "Lhotse"
          ],
          "answer": "Mount Everest",
          "type": "multiple_choice",
          "difficulty": "easy"
        },
        {
          "question": "Which country is home to the Great Barrier Reef?",
          "answer": "Australia",
          "type": "free_text",
          "difficulty": "hard"
        }
      ]
    },
    {
      "title": "Solar System",
      "description": "This quiz contains ten questions about the solar system. Answers include a mix of multiple choice questions and one-worded free text answers.",
      "quiz": [
        {
          "question": "What planet is known as the Red Planet?",
          "answer": "Mars",
          "type": "free_text",
          "difficulty": "easy"
        },
        {
          "question": "Which planet is the largest in our solar system?",
          "answer": "Jupiter",
          "type": "free_text",
          "difficulty": "easy"
        },
        {
          "question": "What is the main component of the sun?",
          "options": [
            "Helium",
            "Hydrogen",
            "Carbon",
            "Oxygen"
          ],
          "answer": "Hydrogen",
          "type": "multiple_choice",
          "difficulty": "easy"
        },
        {
          "question": "Which planet is closest to the sun?",
          "options": [
            "Venus",
            "Earth",
            "Mercury",
            "Mars"
          ],
          "answer": "Mercury",
          "type": "multiple_choice",
          "difficulty": "medium"
        },
        {
          "question": "What is the name of the largest moon of Saturn?",
          "answer": "Titan",
          "type": "free_text",
          "difficulty": "medium"
        },
        {
          "question": "What is the speed of light in a vacuum?",
          "answer": "299792458 m/s",
          "type": "free_text",
          "difficulty": "hard"
        },
        {
          "question": "Which planet has the most rings?",
          "options": [
            "Jupiter",
            "Saturn",
            "Uranus",
            "Neptune"
          ],
          "answer": "Saturn",
          "type": "multiple_choice",
          "difficulty": "easy"
        },
        {
          "question": "What is the name of the fifth planet from the sun?",
          "answer": "Jupiter",
          "type": "free_text",
          "difficulty": "easy"
        },
        {
          "question": "Which planet is known for its extensive and prominent ring system?",
          "options": [
            "Jupiter",
            "Saturn",
            "Uranus",
            "Neptune"
          ],
          "answer": "Saturn",
          "type": "multiple_choice",
          "difficulty": "easy"
        },
        {
          "question": "Which dwarf planet is located in the asteroid belt?",
          "answer": "Ceres",
          "type": "free_text",
          "difficulty": "medium"
        }
      ]
    },
    {
      "title": "Earth Science",
      "description": "This quiz contains ten questions about Earth science. Answers include a mix of multiple choice questions and free text answers.",
      "quiz": [
        {
          "question": "What is the outermost layer of the Earth called?",
          "answer": "Crust",
          "type": "free_text",
          "difficulty": "easy"
        },
        {
          "question": "What is the process by which water vapor turns into liquid water?",
          "answer": "Condensation",
          "type": "free_text",
          "difficulty": "easy"
        },
        {
          "question": "Which gas is most abundant in Earth's atmosphere?",
          "options": [
            "Oxygen",
            "Carbon Dioxide",
            "Nitrogen",
            "Argon"
          ],
          "answer": "Nitrogen",
          "type": "multiple_choice",
          "difficulty": "medium"
        },
        {
          "question": "What is the name of the supercontinent that existed around 300 million years ago?",
          "options": [
            "Gondwana",
            "Laurasia",
            "Pangaea",
            "Rodinia"
          ],
          "answer": "Pangaea",
          "type": "multiple_choice",
          "difficulty": "medium"
        },
        {
          "question": "What is the hardest natural substance on Earth?",
          "answer": "Diamond",
          "type": "free_text",
          "difficulty": "easy"
        },
        {
          "question": "What is the scale used to measure the magnitude of earthquakes?",
          "answer": "Richter scale",
          "type": "free_text",
          "difficulty": "medium"
        },
        {
          "question": "What is the most abundant mineral in the Earth's crust?",
          "options": [
            "Quartz",
            "Feldspar",
            "Mica",
            "Calcite"
          ],
          "answer": "Feldspar",
          "type": "multiple_choice",
          "difficulty": "hard"
        },
        {
          "question": "What is the term for a volcanic rock fragment ejected during an eruption?",
          "answer": "Tephra",
          "type": "free_text",
          "difficulty": "hard"
        },
        {
          "question": "What is the name of the deepest part of the world's oceans?",
          "options": [
            "Mariana Trench",
            "Tonga Trench",
            "Java Trench",
            "Puerto Rico Trench"
          ],
          "answer": "Mariana Trench",
          "type": "multiple_choice",
          "difficulty": "easy"
        },
        {
          "question": "What is the process by which plants make their own food using sunlight?",
          "answer": "Photosynthesis",
          "type": "free_text",
          "difficulty": "easy"
        }
      ]
    },
    {
      "title": "Movies",
      "description": "This quiz contains ten questions about movies. Answers include a mix of multiple choice questions and free text answers.",
      "quiz": [
        {
          "question": "Who directed the movie 'Inception'?",
          "answer": "Christopher Nolan",
          "type": "free_text",
          "difficulty": "easy"
        },
        {
          "question": "Which movie won the Academy Award for Best Picture in 2020?",
          "answer": "Parasite",
          "type": "free_text",
          "difficulty": "easy"
        },
        {
          "question": "Who played the character of Jack Dawson in 'Titanic'?",
          "options": [
            "Leonardo DiCaprio",
            "Brad Pitt",
            "Johnny Depp",
            "Tom Cruise"
          ],
          "answer": "Leonardo DiCaprio",
          "type": "multiple_choice",
          "difficulty": "easy"
        },
        {
          "question": "Which movie features the quote, 'May the Force be with you'?",
          "options": [
            "Star Wars",
            "Star Trek",
            "The Matrix",
            "Guardians of the Galaxy"
          ],
          "answer": "Star Wars",
          "type": "multiple_choice",
          "difficulty": "easy"
        },
        {
          "question": "What is the highest-grossing film of all time?",
          "answer": "Avatar",
          "type": "free_text",
          "difficulty": "medium"
        },
        {
          "question": "Who won the Academy Award for Best Actor in 2021?",
          "answer": "Anthony Hopkins",
          "type": "free_text",
          "difficulty": "medium"
        },
        {
          "question": "Which film series is based on the novels by J.K. Rowling?",
          "options": [
            "The Hunger Games",
            "Harry Potter",
            "The Lord of the Rings",
            "Twilight"
          ],
          "answer": "Harry Potter",
          "type": "multiple_choice",
          "difficulty": "easy"
        },
        {
          "question": "What is the name of the fictional African country in 'Black Panther'?",
          "answer": "Wakanda",
          "type": "free_text",
          "difficulty": "easy"
        },
        {
          "question": "Who composed the score for 'The Lion King'?",
          "options": [
            "Hans Zimmer",
            "John Williams",
            "James Horner",
            "Howard Shore"
          ],
          "answer": "Hans Zimmer",
          "type": "multiple_choice",
          "difficulty": "medium"
        },
        {
          "question": "Which movie features a character named Andy Dufresne?",
          "answer": "The Shawshank Redemption",
          "type": "free_text",
          "difficulty": "hard"
        }
      ]
    },
    {
      "title": "Computer History",
      "description": "This quiz contains ten questions about the history of computers. Answers include a mix of multiple choice questions and free text answers.",
      "quiz": [
        {
          "question": "Who is known as the father of the computer?",
          "answer": "Charles Babbage",
          "type": "free_text",
          "difficulty": "easy"
        },
        {
          "question": "In which year was the first Apple computer released?",
          "answer": "1976",
          "type": "free_text",
          "difficulty": "medium"
        },
        {
          "question": "Which company created the first microprocessor?",
          "options": [
            "Intel",
            "IBM",
            "AMD",
            "Motorola"
          ],
          "answer": "Intel",
          "type": "multiple_choice",
          "difficulty": "medium"
        },
        {
          "question": "Who co-founded Microsoft with Bill Gates?",
          "options": [
            "Steve Jobs",
            "Paul Allen",
            "Larry Page",
            "Sergey Brin"
          ],
          "answer": "Paul Allen",
          "type": "multiple_choice",
          "difficulty": "easy"
        },
        {
          "question": "What was the name of the first electronic general-purpose computer?",
          "answer": "ENIAC",
          "type": "free_text",
          "difficulty": "medium"
        },
        {
          "question": "Which programming language was developed by Dennis Ritchie?",
          "answer": "C",
          "type": "free_text",
          "difficulty": "easy"
        },
        {
          "question": "What is the name of the first graphical web browser?",
          "options": [
            "Mosaic",
            "Netscape Navigator",
            "Internet Explorer",
            "Opera"
          ],
          "answer": "Mosaic",
          "type": "multiple_choice",
          "difficulty": "hard"
        },
        {
          "question": "Who invented the World Wide Web?",
          "answer": "Tim Berners-Lee",
          "type": "free_text",
          "difficulty": "easy"
        },
        {
          "question": "Which company introduced the first laptop computer?",
          "options": [
            "IBM",
            "Apple",
            "Toshiba",
            "HP"
          ],
          "answer": "Toshiba",
          "type": "multiple_choice",
          "difficulty": "medium"
        },
        {
          "question": "What was the name of the first commercially successful personal computer?",
          "answer": "IBM PC",
          "type": "free_text",
          "difficulty": "hard"
        }
      ]
    },
    {
      "title": "Nutrition",
      "description": "This quiz contains ten questions about nutrition. Answers include a mix of multiple choice questions and free text answers.",
      "quiz": [
        {
          "question": "What vitamin is known as the sunshine vitamin?",
          "answer": "Vitamin D",
          "type": "free_text",
          "difficulty": "easy"
        },
        {
          "question": "Which nutrient is essential for muscle growth and repair?",
          "answer": "Protein",
          "type": "free_text",
          "difficulty": "easy"
        },
        {
          "question": "Which mineral is important for healthy bones and teeth?",
          "options": [
            "Iron",
            "Calcium",
            "Potassium",
            "Magnesium"
          ],
          "answer": "Calcium",
          "type": "multiple_choice",
          "difficulty": "medium"
        },
        {
          "question": "What is the main source of energy for the body?",
          "options": [
            "Proteins",
            "Fats",
            "Carbohydrates",
            "Vitamins"
          ],
          "answer": "Carbohydrates",
          "type": "multiple_choice",
          "difficulty": "medium"
        },
        {
          "question": "What is the recommended daily intake of water for an average adult?",
          "answer": "8 cups",
          "type": "free_text",
          "difficulty": "easy"
        },
        {
          "question": "Which vitamin is essential for blood clotting?",
          "answer": "Vitamin K",
          "type": "free_text",
          "difficulty": "medium"
        },
        {
          "question": "Which nutrient helps in the absorption of calcium?",
          "options": [
            "Vitamin A",
            "Vitamin C",
            "Vitamin D",
            "Vitamin E"
          ],
          "answer": "Vitamin D",
          "type": "multiple_choice",
          "difficulty": "medium"
        },
        {
          "question": "What is the term for the process by which the body breaks down food to release energy?",
          "answer": "Metabolism",
          "type": "free_text",
          "difficulty": "hard"
        },
        {
          "question": "Which vitamin is an antioxidant that helps protect cells from damage?",
          "options": [
            "Vitamin A",
            "Vitamin B12",
            "Vitamin C",
            "Vitamin D"
          ],
          "answer": "Vitamin C",
          "type": "multiple_choice",
          "difficulty": "easy"
        },
        {
          "question": "What is the main function of dietary fiber?",
          "answer": "Aids digestion",
          "type": "free_text",
          "difficulty": "easy"
        }
      ]
    },
    {
      "title": "Food",
      "description": "This quiz contains ten questions about food. Answers include a mix of multiple choice questions and free text answers.",
      "quiz": [
        {
          "question": "What is the main ingredient in guacamole?",
          "answer": "Avocado",
          "type": "free_text",
          "difficulty": "easy"
        },
        {
          "question": "Which country is famous for sushi?",
          "answer": "Japan",
          "type": "free_text",
          "difficulty": "easy"
        },
        {
          "question": "What type of pasta is shaped like small rice grains?",
          "options": [
            "Fusilli",
            "Orzo",
            "Penne",
            "Spaghetti"
          ],
          "answer": "Orzo",
          "type": "multiple_choice",
          "difficulty": "medium"
        },
        {
          "question": "Which fruit is known as the 'king of fruits'?",
          "options": [
            "Apple",
            "Mango",
            "Banana",
            "Pineapple"
          ],
          "answer": "Mango",
          "type": "multiple_choice",
          "difficulty": "medium"
        },
        {
          "question": "What is the main ingredient in hummus?",
          "answer": "Chickpeas",
          "type": "free_text",
          "difficulty": "easy"
        },
        {
          "question": "Which vitamin is most abundant in citrus fruits?",
          "answer": "Vitamin C",
          "type": "free_text",
          "difficulty": "easy"
        },
        {
          "question": "What is the name of the Italian dish made of thinly sliced raw meat or fish?",
          "options": [
            "Carpaccio",
            "Risotto",
            "Bruschetta",
            "Gnocchi"
          ],
          "answer": "Carpaccio",
          "type": "multiple_choice",
          "difficulty": "medium"
        },
        {
          "question": "What is the process of preserving food by removing moisture called?",
          "answer": "Dehydration",
          "type": "free_text",
          "difficulty": "hard"
        },
        {
          "question": "Which spice is known as the 'queen of spices'?",
          "options": [
            "Cinnamon",
            "Cardamom",
            "Nutmeg",
            "Clove"
          ],
          "answer": "Cardamom",
          "type": "multiple_choice",
          "difficulty": "medium"
        },
        {
          "question": "What is the main ingredient in a traditional Greek salad?",
          "answer": "Cucumber",
          "type": "free_text",
          "difficulty": "easy"
        }
      ]
    },
    {
      "title": "Popular Culture",
      "description": "This quiz contains ten questions about popular culture. Answers include a mix of multiple choice questions and free text answers.",
      "quiz": [
        {
          "question": "Who is known as the 'King of Pop'?",
          "answer": "Michael Jackson",
          "type": "free_text",
          "difficulty": "easy"
        },
        {
          "question": "Which TV show features the characters Sheldon, Leonard, and Penny?",
          "answer": "The Big Bang Theory",
          "type": "free_text",
          "difficulty": "easy"
        },
        {
          "question": "Which movie franchise features a character named Jack Sparrow?",
          "options": [
            "Harry Potter",
            "Pirates of the Caribbean",
            "The Lord of the Rings",
            "Star Wars"
          ],
          "answer": "Pirates of the Caribbean",
          "type": "multiple_choice",
          "difficulty": "easy"
        },
        {
          "question": "Who is the author of the 'Harry Potter' series?",
          "options": [
            "J.K. Rowling",
            "Stephen King",
            "George R.R. Martin",
            "J.R.R. Tolkien"
          ],
          "answer": "J.K. Rowling",
          "type": "multiple_choice",
          "difficulty": "easy"
        },
        {
          "question": "What is the highest-grossing film of all time?",
          "answer": "Avatar",
          "type": "free_text",
          "difficulty": "medium"
        },
        {
          "question": "Which artist released the album 'Lemonade' in 2016?",
          "answer": "Beyonce",
          "type": "free_text",
          "difficulty": "medium"
        },
        {
          "question": "Which video game series features the character Master Chief?",
          "options": [
            "Call of Duty",
            "Halo",
            "Fortnite",
            "The Legend of Zelda"
          ],
          "answer": "Halo",
          "type": "multiple_choice",
          "difficulty": "medium"
        },
        {
          "question": "What is the name of the coffee shop in the TV show 'Friends'?",
          "answer": "Central Perk",
          "type": "free_text",
          "difficulty": "easy"
        },
        {
          "question": "Which artist is known for the hit song 'Shape of You'?",
          "options": [
            "Ed Sheeran",
            "Justin Bieber",
            "Bruno Mars",
            "Shawn Mendes"
          ],
          "answer": "Ed Sheeran",
          "type": "multiple_choice",
          "difficulty": "easy"
        },
        {
          "question": "Who won the first season of 'American Idol'?",
          "answer": "Kelly Clarkson",
          "type": "free_text",
          "difficulty": "hard"
        }
      ]
    },
    {
      "title": "Cars",
      "description": "This quiz contains ten questions about cars. Answers include a mix of multiple choice questions and free text answers.",
      "quiz": [
        {
          "question": "Which company manufactures the Mustang?",
          "answer": "Ford",
          "type": "free_text",
          "difficulty": "easy"
        },
        {
          "question": "What is the main ingredient in gasoline?",
          "answer": "Petroleum",
          "type": "free_text",
          "difficulty": "easy"
        },
        {
          "question": "Which car brand has a prancing horse as its logo?",
          "options": [
            "Ferrari",
            "Lamborghini",
            "Porsche",
            "Maserati"
          ],
          "answer": "Ferrari",
          "type": "multiple_choice",
          "difficulty": "easy"
        },
        {
          "question": "Which car company produces the Civic?",
          "options": [
            "Toyota",
            "Honda",
            "Nissan",
            "Mazda"
          ],
          "answer": "Honda",
          "type": "multiple_choice",
          "difficulty": "easy"
        },
        {
          "question": "What is the fastest production car in the world as of 2025?",
          "answer": "Bugatti",
          "type": "free_text",
          "difficulty": "medium"
        },
        {
          "question": "Which car company is known for its 'quattro' all-wheel-drive system?",
          "answer": "Audi",
          "type": "free_text",
          "difficulty": "medium"
        },
        {
          "question": "Which car brand is known for the model '911'?",
          "options": [
            "BMW",
            "Mercedes-Benz",
            "Porsche",
            "Jaguar"
          ],
          "answer": "Porsche",
          "type": "multiple_choice",
          "difficulty": "easy"
        },
        {
          "question": "What is the term for the measure of a car's engine power?",
          "answer": "Horsepower",
          "type": "free_text",
          "difficulty": "easy"
        },
        {
          "question": "Which car company introduced the first mass-produced hybrid car?",
          "options": [
            "Toyota",
            "Honda",
            "Ford",
            "Chevrolet"
          ],
          "answer": "Toyota",
          "type": "multiple_choice",
          "difficulty": "medium"
        },
        {
          "question": "What is the name of the first car ever made?",
          "answer": "Benz",
          "type": "free_text",
          "difficulty": "hard"
        }
      ]
    }
  ]
}`;
