from flask import Flask, jsonify, make_response, request
from flask_cors import CORS
import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setup(18, GPIO.OUT)

app = Flask(__name__)
CORS(app)

@app.route('/api/led/toggle', methods=['POST'])
def toggle_led():
    status = request.json['status']
    GPIO.output(18, GPIO.HIGH if status == 1 else GPIO.LOW)
    response = make_response(jsonify({'status': 'success'}))
    response.headers['Access-Control-Allow-Origin'] = '*'
    response.headers['Access-Control-Allow-Methods'] = 'POST'
    response.headers['Access-Control-Allow-Headers'] = 'Content-Type'
    return response

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)

