#version 330 core
out vec4 FragColor;
  
in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D ourTexture;

void main() {
<<<<<<< HEAD
    FragColor = texture(ourTexture, TexCoord) * vec4(ourColor, 1.0);  
}
=======
    FragColor = texture(ourTexture, TexCoord);
}
>>>>>>> 11f63887e9573415f2ed2fed84986ab4c4bd0b4f
