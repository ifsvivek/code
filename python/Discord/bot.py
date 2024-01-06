import os
import discord
import subprocess
from discord.ext import commands, tasks
from dotenv import load_dotenv
import random
import asyncio

load_dotenv()
TOKEN = os.getenv('TOKEN')
intents = discord.Intents.all()
bot = commands.Bot(command_prefix='$', intents=intents)

@bot.event
async def on_ready():
    print(f'Logged in as {bot.user.name} ({bot.user.id})')
    change_status.start()

@tasks.loop(seconds=30)
async def change_status():
    statuses = [
        "Listening to commands",
        "Playing with Discord API",
        "Enjoying the cosmos",
        "Ad Astra - To the stars!",
        "Trying to find the meaning of life, the universe, and everything",
        "Counting backwards from infinity",
        "Dancing like no one is watching in zero gravity",
        "Inventing a new dance move: the wormhole shuffle",
        "Attempting to high-five an alien",
        "Looking for my spaceship keys",
        "Singing karaoke with the stars",
        "Battling space mosquitoes",
        "Avoiding black holes like the plague",
        "Attempting to teach quantum physics to my cat",
        "Hitchhiking across the galaxy",
        "Discussing wormhole traffic jams",
        "Trying to catch a shooting star with a butterfly net",
        "Convincing Pluto it's still a planet",
        "Counting the number of stars in the sky (lost count)",
        "Telling jokes to the moon (it's a tough crowd)",
        "Practicing astronautical yoga",
        "Balancing the universe on my fingertip",
        "Teaching aliens the Macarena",
        "Playing hide and seek with dark matter",
    ]
    new_status = random.choice(statuses)
    await bot.change_presence(activity=discord.Game(name=new_status))

@bot.command()
async def ping(ctx, target):
    result = subprocess.run(['ping', '-c', '4', target], capture_output=True, text=True)
    await ctx.send(f"```{result.stdout}```")

@bot.command(name='repeat')
async def repeat(ctx, *, message):
    await ctx.message.delete()
    print(f"{ctx.author.name} Sent: {message}")
    await ctx.send(message)

@bot.command(name='rules')
@commands.has_permissions(administrator=True)
async def rules(ctx):
    rules_text = (
        "🌟 **Server Rules** 🌟\n\n"
        "1. Be respectful to others.\n"
        "2. No spamming or excessive use of caps.\n"
        "3. Follow Discord's Terms of Service.\n"
        "4. No NSFW content.\n"
        "5. Use appropriate channels for discussions.\n"
        "6. No advertising without permission.\n"
        "7. Have fun and enjoy your stay!"
    )
    await ctx.send(rules_text)

@bot.command(name='purge')
@commands.has_permissions(administrator=True)
async def purge(ctx, amount: int):
    if 1 <= amount <= 100:
        deleted_messages = await ctx.channel.purge(limit=amount + 1)
        await ctx.send(f"Deleted {len(deleted_messages) - 1} messages.")
    else:
        await ctx.send("Please provide a number between 1 and 100 for the purge command.")

@bot.command(name='color')
async def color(ctx, hex_code: str):
    if not is_valid_hex(hex_code):
        await ctx.send("Invalid hex code. Please provide a valid hex code.")
        return
    color_embed = discord.Embed(color=int(hex_code, 16))
    color_embed.set_author(name=f"Color: #{hex_code.upper()}", icon_url=ctx.author.avatar.url)
    await ctx.send(embed=color_embed)

def is_valid_hex(hex_code):
    try:
        int(hex_code, 16)
        return len(hex_code) in [6, 8]
    except ValueError:
        return False

@bot.command()
async def hello(ctx):
    await ctx.send(f"Hello, {ctx.author.name}!")

@bot.command()
async def dice(ctx, sides: int = 6):
    result = random.randint(1, sides)
    await ctx.send(f"You rolled a {result}.")

@bot.command()
async def flip(ctx):
    result = random.choice(["Heads", "Tails"])
    await ctx.send(f"The coin landed on: **{result}**")

@bot.command()
async def shalli(ctx):
    result = random.choice(["Yes", "No"])
    await ctx.send(result)

bot.run(TOKEN)