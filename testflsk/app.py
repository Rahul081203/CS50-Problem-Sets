from flask import Flask, render_template, request
from cs50 import SQL
import os

app=Flask(__name__)
db=SQL("sqlite:///birthdays.db")

@app.route("/", methods=['GET','POST'])
def index():
    return render_template("index.html")