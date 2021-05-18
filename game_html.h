String header = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
 
char html_1[]  PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
  <meta name='viewport' content='width=device-width, initial-scale=1.0'/>
  <meta charset='utf-8'>
  <link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
  <title>Casse Cou....</title>
  
    <style>
        body {
          font-family: Arial, Helvetica, sans-serif;
          color: white;
        }
        canvas {
            background: #111;
            display: block;
            border-radius: 4px;
        }
        .game {
          background-color: #222;
          position: relative;
          display: flex;
          align-items: center;
          justify-content: center;
          flex-direction: column;
          height: 100vh;
          margin: 0;
        }

    </style>
</head>
<body>
    <section class="game" id="game">
            <canvas id="canvas" width="600" height="500"></canvas>
            <div class="gameover" style="display: none;"> <img src="https://i.pinimg.com/originals/14/5d/d0/145dd02dbaa43b6ad940451584b07b02.gif"> </div>
            <div> SCORE: <span class="score"></span></div>
            <button class="w3-btn w3-border w3-round-xxlarge w3-yellow"> REPLAY </button>
      </section>
 <script>
      //Initialisation du canvas et définition du context
      const canvas = document.getElementById('canvas');
      const ctx = canvas.getContext('2d');
      let data_obj = new Object()
      let data_briques_obj = new Object();
      var Time = [0]
      
      // Ajout de la bordure au canvas
      canvas.style.border = '1px solid #6198d8';
      ctx.lineWidth = 1;
      

        window.onload = function(e)
        { 
          init();
        }

        //Déssiner la planche
        function drawPaddle() {
            ctx.beginPath();
        
            ctx.fillStyle = "#fff";
            ctx.fillRect(data_obj.barre_x, data_obj.barre_y, 100, 10);
            ctx.strokeStyle = '#6198d8';
            ctx.strokeRect(data_obj.barre_x, data_obj.barre_y, 100, 10);
        
            ctx.closePath();
        }

        //Déssiner la balle
        function drawBall() {
            ctx.beginPath();
        
            ctx.arc(data_obj.ball_x, data_obj.ball_y, 5, 0, Math.PI*2);
            ctx.fillStyle = "blue";
            ctx.fill();
        
            ctx.strokeStyle = '#6198d8';
            ctx.stroke();
        
            ctx.closePath();
        }

        //Dessiner les briques
        function drawBricks() {
            data_briques_obj.row.forEach(brick => {
                    if (brick.brique_status) {
                        ctx.beginPath();
        
                        ctx.rect(brick.brique_x, brick.brique_y, 90, 10);
                        ctx.fillStyle = "#fff";
                        ctx.fill();
        
                        ctx.closePath();
                    }
                })
        }

        function clear_brique() {
          if(data_obj.clear_brique != -1) {
            data_briques_obj.row[data_obj.clear_brique].brique_status = false;
          }
        }

        function setScore() {
          document.querySelector(".score").innerHTML = data_obj.score;
        }

        function gameOverGIF()
        {
          $("#canvas").hide();
          $(".gameover").fadeIn();
        }
        
        //Relatif à tous les dessins du jeu
        function draw() {
            drawBricks();
            drawPaddle();
            drawBall();
            clear_brique();
            setScore();
        }

        function loop() {
            ctx.clearRect(0, 0, canvas.width, canvas.height);
            draw();      
            //requestAnimationFrame(loop);
        }
    
                
        function init() 
        {
          Socket = new WebSocket('ws://' + window.location.hostname + ':81/');
          Socket.onopen = async function(event) {
            console.log("Connexion établie.");
            
            // Lorsque la connexion se termine.
            this.onclose = function(event) {
                console.log("Connexion terminé.");
            };
        
            // Lorsque le serveur envoi un message.
            this.onmessage = function(event) {
                
                //console.log("Message:", event.data);
                if(JSON.parse(event.data).hasOwnProperty("row"))
                {
                  data_briques_obj = JSON.parse(event.data);
                }
                else {
                  data_obj = JSON.parse(event.data);
                }

                loop();

                if(data_obj.gameover) {
                  gameOverGIF();
                }
            };
        
            // Envoi d'un message vers le serveur.
                 //this.send("Hello world!");
          };
        }
        
       
        function sendText(data)
        {
          Socket.send(data);
        }

        function sleep(ms) {
          return new Promise(resolve => setTimeout(resolve, ms));
        }

        function getFPS() {
          let f = Date.now();
          Time.push(f);
          let fps = 1000/(Time[2]-Time[1])
          while(Time.length  > 3) {
            Time.shift();
          }
          console.log(fps);
        }
        document.querySelector("button").addEventListener('click', () => {
          sendText("replay");
          window.location.reload();
        })
</script> 
<script src="https://code.jquery.com/jquery-3.6.0.min.js"> </script>
</body>
</html>
)=====";
