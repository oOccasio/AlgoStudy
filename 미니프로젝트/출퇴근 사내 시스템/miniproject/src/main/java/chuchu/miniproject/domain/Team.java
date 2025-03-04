package chuchu.miniproject.domain;

import jakarta.persistence.*;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Getter
@Entity
@NoArgsConstructor
public class Team {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @Column(nullable = false, length = 25)
    private String name;

    @Column(length = 25)
    private String manager;

    @Column
    private Integer memberCount;

    public Team(Builder builder) {
        this.name = builder.name;
        this.manager = builder.manager;
        this.memberCount = builder.memberCount;
    }

    public static Builder builder(){
        return new Builder();
    }


    public static class Builder{
        private String name;
        private String manager;
        private Integer memberCount;

        public Builder name(String name){
            this.name = name;
            return this;
        }

        public Builder manager(String manager){
            this.manager = manager;
            return this;
        }

        public Builder memberCount(Integer memberCount){
            this.memberCount = (memberCount != null) ? memberCount : 0;
            return this;
        }

        public Team build(){
            return new Team(this);
        }
    }

}
