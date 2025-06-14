# Converted from hand.ipynb

# %%
!git clone https://github.com/otuva/handwriting-synthesis
&cd handwriting-synthesis
!python -m venv venv
!source venv/bin/activate
!pip install -r requirements.txt

# %%
from handwriting_synthesis.hand import Hand

lines = [
    "In the heart of a quiet town,",
    "An old clock tower stood tall and proud.",
    "Its hands, though rusty, moved with grace,",
    "Counting moments, day and night.",
    "",
    "One day, a young girl stood before it,",
    "Her eyes full of wonder and dreams.",
    "I wish, she whispered to the ticking clock,",
    "To make every moment count.",
    "",
    "The clock seemed to listen,",
    "Its hands moving slower, more deliberately.",
    "Time stretched and wove into memories,",
    "As the girl lived her days fully and bright.",
    "",
    "And so, the old clock tower,",
    "Once a simple keeper of time,",
    "Became a witness to the richness of life,",
    "As each second became a treasured moment."
]

biases = [.75 for _ in lines]
styles = [9 for _ in lines]
stroke_colors = ['black' for _ in lines]
stroke_widths = [1 for _ in lines]  # Use a consistent stroke width

hand = Hand()
hand.write(
    filename='img/short_story_black.svg',
    lines=lines,
    biases=biases,
    styles=styles,
    stroke_colors=stroke_colors,
    stroke_widths=stroke_widths
)


