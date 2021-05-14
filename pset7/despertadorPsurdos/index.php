<!DOCTYPE html>

    <head>
        
        <style>
            body    {background-color: black;}
            h1      {text-align:center; color: blanchedalmond; }
            p       {text-align:center; color: white; }
            img     {display: block; }
            .center
            {
                margin-left: auto;
                margin-right: auto;
            }
            table   
            {
                border: 10px groove rebeccapurple;
                padding: 5px;
                width: 550px;
                border-collapse: collapse;
            }
            th, td 
            {
                border: 5px solid;
                padding: 2px;
                border-color: green;
                color: white;
                text-align: center;
            }
        </style>

        <title>Despertador Para Surdos</title>

    </head>


    <body>
        <h1>Despertador para surdos</h1>

        <image src="2021 03 Quadrado Azul 3.jpg" class="center" alt="Foto do Despertador" widht="400px" height="400px">
        
        <form method="post" <!-- action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>" -->>
            <table class="center">
                <caption>Escolha o seu!</caption>
                <tr>
                    <th>Modelo</th>
                    <th>Valor</th>
                    <th>Comprar</th>
                </tr>
                <tr>
                    <td>Com cabo 2 pilhas AA</td>
                    <td>R$100</td>
                    <td><input name="modelo1" type="checkbox" ></td>
                </tr>
                <tr>
                    <td>Com cabo Bateria 9V</td>
                    <td>R$100</td>
                    <td><input name="modelo2" type="checkbox" ></td>
                </tr>
                <tr>
                    <td>Sem cabo Bateria 9V</td>
                    <td>R$ 90</td>
                    <td><input name="modelo3" type="checkbox" ></td>
                </tr>
            </table>

            <br>
            <p>
                Digite o seu nome
                <input name="nome" type="text">
                <br><br>
                <input style="color:black" type="submit" value="Comprar!">
            </p>
        </form>

        <h1>
            <?php
                if ($_POST["nome"] != "")
                { 
                    echo "Seu nome é ";
                    echo $_POST["nome"];
                }
            ?>
        </h1>

    </body>

</html>

